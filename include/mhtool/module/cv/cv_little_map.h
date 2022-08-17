//
// Created by huhua on 2022/2/21.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_CV_CV_LITTLE_MAP_H_
#define MH_TOOL_INCLUDE_MHTOOL_CV_CV_LITTLE_MAP_H_
#include <opencv2/core.hpp>

namespace mh {
namespace cv {
/**
 * @param mat
 * @return 是否有小地图
 */
bool hasLittleMap(::cv::InputArray mat);
}
}
#endif //MH_TOOL_INCLUDE_MHTOOL_CV_CV_LITTLE_MAP_H_
