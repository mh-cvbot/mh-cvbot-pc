//
// Created by huhua on 2022/2/13.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_MH_MH_MAIN_LOOP_H_
#define MH_TOOL_INCLUDE_MHTOOL_MH_MH_MAIN_LOOP_H_
#include <QLabel>

// bad name?
class MHMainLoop {
 private:
  QLabel *_label;
  bool _start = false;

 public:
  inline MHMainLoop(QLabel *label): _label(label) {};

 public:
  void start();

  void stop();

 private:
  void run();
};
#endif //MH_TOOL_INCLUDE_MHTOOL_MH_MH_MAIN_LOOP_H_
