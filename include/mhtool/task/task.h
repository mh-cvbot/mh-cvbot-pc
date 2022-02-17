//
// Created by huhua on 2022/2/15.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_COMM_TASK_ITASK_H_
#define MH_TOOL_INCLUDE_MHTOOL_COMM_TASK_ITASK_H_
#include "mhtool/comm/Result.h"

class Task {
 private:
  std::string name;

 public:
  Task(const std::string &_name);
  Task();
  /**
   * throw exception when failed?
   */
  virtual Result realRun() = 0;

  Result run();
};
#endif //MH_TOOL_INCLUDE_MHTOOL_COMM_TASK_ITASK_H_
