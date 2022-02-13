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
  MH mh;
  while (true) {
    if (!this->_start) {
      break;
    }
    auto begin = eb::currentTimeInMillisecond();

    try {
      mh.refresh();
      if (mh.gameWin()->getId() == nullptr) {
        this->_label->setText("请开启并登录游戏");
        continue;
      }

      cv::Mat mat;
      // 为什么这里又不对了？
      // 难道是qt的问题，还是opencv的问题呢？
      mh.gameWin()->screenshot(mat, 2);
//      std::cout << "channel: " << mat.channels() << "imgSize: " << mat.size().width << ", height: " << mat.size().height << std::endl;
//      cv::imwrite("tmp11.bmp", mat);
//      cv::imshow("test", mat);
//      cv::waitKey(0);

      if (eb::gbk2utf8(mh.gameWin()->title) == "梦幻西游 ONLINE") {
        this->_label->setText("没有登录");
        continue;
      }

      mh::PosIndicator pos;
      auto success = mh::cv::posIndicator(mat, &pos);
      std::cout << "pos: " << pos << std::endl;

      if (!success) {
        this->_label->setText("获取不到坐标");
      } else {
        this->_label->setText(QString("%1 [%2,%3]").arg(QString(pos.name.c_str())).arg(pos.pos.x).arg(pos.pos.y));
      }


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
