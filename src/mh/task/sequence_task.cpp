//
// Created by th on 2022/2/16.
//

#include <mhtool/task/sequence_task.h>

Result SequenceTask::realRun() {
  for (auto &task: tasks) {
    auto rst = task.realRun();
    if (!rst.isOk()) {
      return rst;
    }
  }

  return {0, ""};
}
