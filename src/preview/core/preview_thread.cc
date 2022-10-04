//
// Created by huhua on 2022/10/3.
//
#include "./preview_thread.h"
#include <mhtool/mh/mh.h>

void PreviewThread::run() {
  std::cout << "PreviewThread::run() called" << std::endl;
  auto win = mh::MH::inst()->gameWin();

  while (true) {
    if (isFinished()) {
      break;
    }
    win->screenshot(cachedSnap, 2);
    emit onPreviewGot(cachedSnap);
  }
}
