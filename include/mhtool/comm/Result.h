//
// Created by huhua on 2022/2/15.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_COMM_RESULT_H_
#define MH_TOOL_INCLUDE_MHTOOL_COMM_RESULT_H_
#include <string>
#include <utility>

/**
 * Why I need write result again and again?
 */
class Result {
 public:
  int code;
  std::string msg;
  static int CODE_OK;

  inline Result(int _code, std::string _msg): code(_code), msg(std::move(_msg)) {};

  inline static Result withOk(const std::string &msg) {
    // I can return something like this?
    return {CODE_OK, msg};
  };

  inline bool isOk() const {
    return this->code == CODE_OK;
  }

  bool checkWithThrow();

};
#endif //MH_TOOL_INCLUDE_MHTOOL_COMM_RESULT_H_
