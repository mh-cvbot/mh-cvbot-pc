//
// Created by huhua on 2021/10/17.
//

#ifndef MH_TOOL_CV_H
#define MH_TOOL_CV_H
#include <easybot/easybot.h>
#include "./cv_img.h"

namespace mt {
    namespace cv {
        eb::Coordinate cvCoord(const mt::cv::CVImg &img);
    }
}
#endif //MH_TOOL_CV_H
