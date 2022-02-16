//
// Created by huhua on 2022/2/15.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_MH_TASK_BAOTU_TASK_H_
#define MH_TOOL_INCLUDE_MHTOOL_MH_TASK_BAOTU_TASK_H_

#include "task.h"
#include <stdexcept>
#include <iostream>

#include "mhtool/mh/data.h"

class BaotuTask: public Task {
 public:
  Result run() override;
};

#endif //MH_TOOL_INCLUDE_MHTOOL_MH_TASK_BAOTU_TASK_H_
