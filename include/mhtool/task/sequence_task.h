//
// Created by th on 2022/2/16.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_TASK_SEQUENCE_TASK_H_
#define MH_TOOL_INCLUDE_MHTOOL_TASK_SEQUENCE_TASK_H_
#include <vector>
#include "./task.h"

class SequenceTask: public Task {
 protected:
  std::vector<Task> tasks;

 public:
  Result realRun() override;
};
#endif //MH_TOOL_INCLUDE_MHTOOL_TASK_SEQUENCE_TASK_H_
