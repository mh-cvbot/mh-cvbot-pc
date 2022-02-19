//
// Created by th on 2022/2/17.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_MH_SEND_POINT_H_
#define MH_TOOL_INCLUDE_MHTOOL_MH_SEND_POINT_H_
#include <opencv2/core.hpp>

namespace mh {
class City;
class SendPoint {
 public:
  City *city;
  cv::Point2i point;
};
}
#endif //MH_TOOL_INCLUDE_MHTOOL_MH_SEND_POINT_H_
