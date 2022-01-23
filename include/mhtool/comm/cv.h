//
// Created by huhua on 2022/1/4.
//

#ifndef MH_TOOL_CV_H
#define MH_TOOL_CV_H
#include <mhtool/comm/pos_indicator/pos_indicator.h>

#include <opencv2/opencv.hpp>

// any better name?
namespace mh {
namespace cv {
PosIndicator posIndicator(const ::cv::Mat &mat);
}
}

#endif //MH_TOOL_CV_H
