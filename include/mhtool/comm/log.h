//
// Created by huhua on 2022/2/16.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_LOG_H_
#define MH_TOOL_INCLUDE_MHTOOL_LOG_H_
#include <string>
#include <QString>

// Log 太多了啊。
class Log {
 public:
  static void i(const std::string&);
  static void i(const char* str);
  static void i(const QString &str);
};
#endif //MH_TOOL_INCLUDE_MHTOOL_LOG_H_
