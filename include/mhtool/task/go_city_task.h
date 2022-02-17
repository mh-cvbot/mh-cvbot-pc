//
// Created by huhua on 2022/2/15.
//

#ifndef MH_TOOL_SRC_MH_TASK_GO_CITY_TASK_H_
#define MH_TOOL_SRC_MH_TASK_GO_CITY_TASK_H_

#include "mhtool/task/task.h"
#include "mhtool/mh/city/city.h"

class GoCityTask: public Task {
 private:
  mh::City *to;
 public:
  GoCityTask(mh::City *_to);
};

#endif //MH_TOOL_SRC_MH_TASK_GO_CITY_TASK_H_
