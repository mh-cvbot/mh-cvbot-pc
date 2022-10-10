//
// Created by huhua on 10/6/2022.
//

#include <mhtool/core/cv/game_pos_cv.h>
#include <mhtool/util/cv_util.h>
#include <tesseract/baseapi.h>
#include <boost/algorithm/string/trim.hpp>
#include <regex>

static GamePos cv_middle_state(const cv::Mat &mat) {
  ::cv::Mat roi(mat, ::cv::Range(23, 43), ::cv::Range(18, 130));
  ::cv::Mat _mat = roi;
//  mh::cv1::white(roi, _mat1);
//  _mat1 = ~_mat1;
//  // try double you
//  ::cv::Mat _mat;
//  ::cv::resize(_mat1, _mat, ::cv::Size(_mat1.size().width * 2, _mat1.size().height * 2), 0, 0, ::cv::INTER_NEAREST);

  auto *tess = new tesseract::TessBaseAPI();
  // 为什么mac上可以出来？？
  if (tess->Init(nullptr, "chi_sim+eng")) {
    std::cerr << "tess refresh failed." << std::endl;
    // I want throw an exception!!
    return {};
  }

  tess->SetPageSegMode(tesseract::PSM_SINGLE_LINE);
  tess->SetImage(_mat.data, _mat.cols, _mat.rows, _mat.channels(),
                 static_cast<int>(_mat.step));

  // 为什么返回的string不能被regex？
  auto _rstText = tess->GetUTF8Text();

  auto text = std::string(_rstText);
  std::cout << "text: " << text << std::endl;
  text.erase(std::remove(text.begin(), text.end(), ' '), text.end());
  boost::algorithm::trim(text);
  tess->End();
  delete tess;
  delete []_rstText;
  const std::regex r(R"~((.*)(\[(\d+),(\d+)\]))~");

  std::cmatch m;
  auto rst = std::regex_match(text.c_str(), m, r);
  GamePos gamePos;
  if (rst && m.size() == 5) {
    gamePos.name = m.str(1);
    gamePos.pos = eb::Pos(std::stoi(m.str(3)), std::stoi(m.str(4)));
    return gamePos;
  }
}

GamePos GamePosCV::cv(const cv::Mat &mat) {
  return cv_middle_state(mat);
}
