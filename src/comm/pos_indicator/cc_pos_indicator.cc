//
// Created by huhua on 2022/1/24.
//
#include <mhtool/cv.h>
#include <easybot/easybot.h>
#include <mhtool/comm/pos_colors.h>
#include <mhtool/cv/cv_pos_indicator.h>
#include "./pos_indicator_land_mark.h"
#include <tesseract/baseapi.h>
#include <opencv2/opencv.hpp>
#include <mhtool/cv.h>
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

bool posIndicator(const ::cv::Mat &mat, PosIndicator *out) {
  auto tmp = posIndicatorState(mat, &out->state);
  if (!tmp) {
    return false;
  }

  if (out->state == PosIndicatorState::MIDDLE) {
    // ok, first create the right image
    // do you want fix hsv?
    tesseract::TessBaseAPI *tess = new tesseract::TessBaseAPI();
    if (tess->Init(nullptr, "chi_sim+eng")) {
      std::cerr << "tess init failed." << std::endl;
      return false;
    }

    ::cv::Mat roi(mat, ::cv::Range(23, 43), ::cv::Range(18, 130));
    ::cv::Mat _mat;
    mh::cv::white(roi, _mat);
    ::cv::imshow("img", _mat);
    // ok, get the img
    tess->SetPageSegMode(tesseract::PSM_SINGLE_LINE);
    tess->SetImage(_mat.data, _mat.cols, _mat.rows, _mat.channels(), _mat.step);
    auto text = tess->GetUTF8Text();
    std::cout << text << std::endl;
    ::cv::waitKey(0);
  }
  return false;
}

}
}
