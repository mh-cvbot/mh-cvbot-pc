//
// Created by huhua on 2022/2/15.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_COMM_TASK_ITASK_H_
#define MH_TOOL_INCLUDE_MHTOOL_COMM_TASK_ITASK_H_
#include <mhtool/comm/Result.h>

class ITask {
  /**
   * throw exception when failed?
   */
  virtual Result run() = 0;
};
#endif //MH_TOOL_INCLUDE_MHTOOL_COMM_TASK_ITASK_H_
