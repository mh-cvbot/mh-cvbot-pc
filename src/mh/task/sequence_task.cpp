//
// Created by th on 2022/2/16.
//

#include <mhtool/task/sequence_task.h>

Result SequenceTask::run() {
  for (auto &task: tasks) {
    task.run();
  }
  return {}
}
