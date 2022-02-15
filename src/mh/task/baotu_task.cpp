//
// Created by huhua on 2022/2/15.
//
#include <mhtool/mh/task/baotu_task.h>

Result BaotuTask::run() {
  try {
    auto xiaoer = mh::city::changan->jiudian->xiaoer;
    xiaoer->come().checkWithThrow();
    xiaoer->clickMe().checkWithThrow();
    BaotuTaskInfo info;
    xiaoer->takeBaotuTask(&info).checkWithThrow();
    // assert have the task.
  } catch (std::runtime_error &err) {
    std::cerr << err.what() << std::endl;
  }
  try {
    auto xiaoer = mh::city::changan->jiudian->xiaoer;
    xiaoer->come().checkWithThrow();
    xiaoer->clickMe().checkWithThrow();
    BaotuTaskInfo info;
    xiaoer->takeBaotuTask(&info).checkWithThrow();
    // assert have the task.
  } catch (std::runtime_error &err) {
    std::cerr << err.what() << std::endl;
  }
}