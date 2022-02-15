//
// Created by huhua on 2021/9/28.
//

#ifndef MH_TOOL_MH_H
#define MH_TOOL_MH_H

#include <string>
#include "./mh_path.h"
#include "mhtool/comm/Result.h"
#include <easybot/easybot.h>

/**
 * ok, for now, only consider for just on account
 */
class MH {
 private:
  eb::Process _pTab;
  eb::Process _pMain;
  eb::Window _win;
  eb::Window _gameWin;

 public:
  MH();
  static MH* _inst;
  static MH* inst();
  void refresh();
  eb::Window *gameWin();
  eb::Process *pMain();

  /**
   * 检查是否已经开启并登录了
   * @return
   */
  Result checkHasStart();

  static std::string MH_MAIN_EXE;
  static std::string MH_TAB_EXE;
  const static int CONTENT_WIDTH = 800;
  const static int CONTENT_HEIGHT = 600;

  int startedCount();

  void start();

  bool hasInstalled();

  std::string getInstallPath();

  MhPath getPath();
};
#endif //MH_TOOL_MH_H
