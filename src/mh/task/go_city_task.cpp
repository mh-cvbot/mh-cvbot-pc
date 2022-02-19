//
// Created by huhua on 2022/2/15.
//

#include "mhtool/task/go_city_task.h"

GoCityTask::GoCityTask(mh::City *_to): to(_to)
  , Task(std::string("到") + _to->name()) {
  // How to do?
}