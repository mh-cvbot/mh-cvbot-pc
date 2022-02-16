//
// Created by huhua on 2022/1/24.
//
#include <mhtool/cv.h>
#include <mhtool/comm/module/pos_colors.h>
#include <mhtool/cv/cv_pos_indicator.h>
#include "./pos_indicator_land_mark.h"
#include <tesseract/baseapi.h>
#include <opencv2/opencv.hpp>
#include <regex>
#include <boost/algorithm/string.hpp>
// how about namespace without indent?
namespace mh {
namespace cv {

// I don't have any better idea.
PosIndicatorLandMark _middle({9, 50});

// Ok, now you can write a text.
bool posIndicatorState(const ::cv::Mat &mat, mh::PosIndicatorState *out) {
  if (_middle.pcs()->check(mat)) {
    *out = mh::PosIndicatorState::MIDDLE;
    return true;
  }

  return false;
}

// how to deal with you??
bool posIndicator(const ::cv::Mat &mat, PosIndicator *out) {
  auto tmp = posIndicatorState(mat, &out->state);
  std::cout << "tmp: " << tmp << ", state: " << out->state << std::endl;
  if (!tmp) {
    return false;
  }

  if (out->state == PosIndicatorState::MIDDLE) {
    ::cv::Mat roi(mat, ::cv::Range(23, 43), ::cv::Range(18, 130));
    ::cv::Mat _mat1;
    mh::cv::white(roi, _mat1);
    _mat1 = ~_mat1;
    // try double you
    ::cv::Mat _mat;
    ::cv::resize(_mat1, _mat, ::cv::Size(_mat1.size().width * 2, _mat1.size().height * 2), 0, 0, ::cv::INTER_NEAREST);
//    ::cv::imshow("test", _mat);
//    ::cv::waitKey(0);

    auto *tess = new tesseract::TessBaseAPI();
    // 为什么mac上可以出来？？
    if (tess->Init(nullptr, "chi_sim+eng")) {
      std::cerr << "tess refresh failed." << std::endl;
      return false;
    }

    tess->SetPageSegMode(tesseract::PSM_SINGLE_LINE);
    tess->SetImage(_mat.data, _mat.cols, _mat.rows, _mat.channels(), _mat.step);

    // 为什么返回的string不能被regex？
    auto _rstText = tess->GetUTF8Text();

    auto text = std::string(_rstText);
    text.erase(std::remove(text.begin(), text.end(), ' '), text.end());
    boost::algorithm::trim(text);
    tess->End();
    delete tess;
    delete []_rstText;
    std::cout << "text: " << text << std::endl;

    const std::regex r(R"~((.*)(\[(\d+),(\d+)\]))~");

    std::cmatch m;
    auto rst = std::regex_match(text.c_str(), m, r);
    if (rst && m.size() == 5) {
      out->name = m.str(1);
      out->pos = ::cv::Point2i(std::stoi(m.str(3)), std::stoi(m.str(4)));
      return true;
    }
  }
  return false;
}

}
}
