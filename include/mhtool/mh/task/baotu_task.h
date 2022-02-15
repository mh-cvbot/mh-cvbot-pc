//
// Created by huhua on 2022/2/15.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_MH_TASK_BAOTU_TASK_H_
#define MH_TOOL_INCLUDE_MHTOOL_MH_TASK_BAOTU_TASK_H_

#include <mhtool/mh/task/ITask.h>
#include <stdexcept>

#include <mhtool/mh/data.h>

class BaotuTask: public ITask {
  
  Result run() override {
    try {
      mh::city::changan->jiudian->come().checkWithThrow();
    } catch (std::runtime_error &err) {
    }
  }
  
};

#endif //MH_TOOL_INCLUDE_MHTOOL_MH_TASK_BAOTU_TASK_H_
