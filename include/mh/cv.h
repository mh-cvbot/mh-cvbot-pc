//
// Created by huhua on 2022/1/4.
//

#ifndef MH_TOOL_CV_H
#define MH_TOOL_CV_H
#include <opencv2/opencv.hpp>
#include "modal/pos.h"

namespace mh {
    namespace cv {
        mh::modal::Pos pos(const ::cv::Mat &img);
    }
}
#endif //MH_TOOL_CV_H
