//
// Created by huhua on 2022/2/15.
//

#ifndef MH_TOOL_SRC_MH_TASK_GO_CITY_TASK_H_
#define MH_TOOL_SRC_MH_TASK_GO_CITY_TASK_H_

#include <mhtool/mh/task/ITask.h>
#include "mhtool/mh/city/city.h"

class GoCityTask: public ITask {
 private:
  mh::City *_to;
 public:
  inline GoCityTask(mh::City *to): _to(to);

  bool run() override {
  }
};

#endif //MH_TOOL_SRC_MH_TASK_GO_CITY_TASK_H_
