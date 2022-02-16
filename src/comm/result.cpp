//
// Created by huhua on 2022/2/15.
//

#include <mhtool/comm/result.h>
#include <stdexcept>

int Result::CODE_OK = 0;

bool Result::checkWithThrow() {
  auto isOk = code == CODE_OK;
  if (!isOk) {
    throw std::runtime_error(this->msg);
  }
  return isOk;
}
