//
// Created by th on 2022/2/17.
//

#include <mhtool/task/task.h>
#include <mhtool/comm/log.h>

#include <utility>

Result Task::run() {
  Log::i(this->name + " begin running");
  auto rst = this->realRun();
  if (!rst.isOk()) {
    Log::i(this->name + " Failed!!!!: " + rst.msg);
  }
  return rst;
}

Task::Task(std::string _name): name(std::move(_name)) {

}

Task::Task(): Task("Unknown name") {

}
