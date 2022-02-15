//
// Created by huhua on 2021/10/5.
//

#ifndef MH_TOOL_LOG_VIEW_H
#define MH_TOOL_LOG_VIEW_H

#include <QWidget>

#include <vector>
#include <string>

class TaskLogView: public QWidget {
 public:
  TaskLogView(QWidget *parent = nullptr);

 private:
  std::vector<std::string> logs;
  QStringList _logs;
 public:
  void clear();
  void add(const std::string& log);
  void addError(const std::string &log);
};


#endif //MH_TOOL_LOG_VIEW_H
