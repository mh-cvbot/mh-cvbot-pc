//
// Created by huhua on 2022/10/3.
//

#ifndef MH_CVBOT_SRC_CORE_STATIC_REGION_SR_12_PLUS_H_
#define MH_CVBOT_SRC_CORE_STATIC_REGION_SR_12_PLUS_H_

#include "../../../../src/core/static_region/static_region.h"

/**
 * 12+ 适龄提醒，在首页
 */
class SR12Plus: public StaticRegion {
 public:
  inline SR12Plus(): StaticRegion("12plus",
                                  PosColors({
                                  {{36, 17}, {20, 151, 219}},
                                  {{27, 36}, {238, 248, 253}},
                                  {{48, 63}, {23, 23, 23}}
                                  }), "12plus in home page."){}
};

#endif //MH_CVBOT_SRC_CORE_STATIC_REGION_SR_12_PLUS_H_
