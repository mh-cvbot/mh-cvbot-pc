//
// Created by huhua on 2022/2/23.
//

#ifndef MH_TOOL_TEST_CV_INFO_H_
#define MH_TOOL_TEST_CV_INFO_H_
#include <string>
#include <easybot/easybot.h>

// any better idea?

struct CvInfo {
  std::string name;
  int x;
  int y;

  struct LittleMap {
    int left;
    int top;
    int width;
    int height;
  } littleMap;

  bool hasLittleMap() {
    return littleMap.left >= 0;
  }
};

#endif //MH_TOOL_TEST_CV_INFO_H_
