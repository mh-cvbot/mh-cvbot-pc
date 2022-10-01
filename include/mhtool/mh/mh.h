//
// Created by huhua on 2021/9/28.
//

#ifndef MH_TOOL_MH_H
#define MH_TOOL_MH_H

#include <string>
#include "mhtool/mh/mh_path.h"
#include "mhtool/comm/Result.h"
#include "easybot/easybot.h"
#include "mhtool/mh/pos_indicator.h"
#include <opencv2/opencv.hpp>

// is you right??
namespace mh {
class MH {
 private:
  eb::Process _pTab;
  eb::Process _pMain;
  eb::Window _win;
  eb::Window _gameWin;
  static MH* _inst;

 public:
  MH();

  /**
   * single instance.
   */
  static MH* inst();

  void refresh();
  eb::Window *gameWin();
  eb::Process *pMain();

  /**
   * 检查是否已经开启并登录了
   */
  Result checkHasLogin();

  static std::string MH_MAIN_EXE;
  static std::string MH_TAB_EXE;
  const static int CONTENT_WIDTH = 800;
  const static int CONTENT_HEIGHT = 600;

  int startedCount();

  void start();

  bool hasInstalled();

  std::string getInstallPath();

  MhPath getPath();

  PosIndicator pos(bool waitStop = false);

  void waitStop();

  Result goByMouseClick(const PosIndicator &pos, const eb::Pos &dst);

  Result goByLittleMap(const eb::Pos &dst);
};
}
#endif //MH_TOOL_MH_H
