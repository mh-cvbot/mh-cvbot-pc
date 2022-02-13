//
// Created by huhua on 2022/2/13.
//

#include <easybot/easybot.h>
#include <mhtool/mh/mh.h>
#include <mhtool/mh/mh_main_loop.h>
#include <mhtool/cv.h>
#include <thread>

static long minDuration = 1000;

void MHMainLoop::start() {
  this->_start = true;
  std::thread t(&MHMainLoop::run, this);
  t.detach();
}

void MHMainLoop::stop() {
  this->_start = false;
}

void MHMainLoop::run() {
  while (true) {
    if (!this->_start) {
      break;
    }
    auto begin = eb::currentTimeInMillisecond();

    try {
      // 开始的逻辑怎么写合适？
      auto pMhTab = eb::Process::findByName(MH::MH_TAB_EXE);
      auto pMhMain = eb::Process::findByName(MH::MH_MAIN_EXE);


      if (pMhMain.getPid() == 0) {
        this->_label->setText("请开启游戏");
        continue;
      }

      auto window = pMhTab.getBiggestWindow();

      auto subWindows = window.getSubWindows();

      auto gameWindow = subWindows[1];

//      cv::Mat mat;
//      gameWindow.screenshot(mat, 2);
//      cv::imshow("main loop", mat);
//      cv::waitKey(0);

      if (eb::gbk2utf8(window.title) == "梦幻西游 ONLINE") {
        this->_label->setText("没有登录");
        continue;
      }

      // what to do next?
      mh::PosIndicator pos;
      cv::Mat mat;
      gameWindow.screenshot(mat, 2);
      mh::cv::posIndicator(mat, &pos);
      std::cout << "pos: " << pos << std::endl;

      this->_label->setText("请继续完成逻辑");
    } catch (std::runtime_error &err) {
      std::cout << "has error: " << err.what() << std::endl;
      this->_start = false;
      this->_label->setText("发生了一些错误");
      break;
    }

    auto now = eb::currentTimeInMillisecond();
    auto diff = now - begin;
    if (diff > 0) {
      // look's wait not work?
      std::this_thread::sleep_for(std::chrono::milliseconds(diff));
    }
  }
}
