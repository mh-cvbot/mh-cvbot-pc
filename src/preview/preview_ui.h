//
// Created by huhua on 2022/9/24.
//

#ifndef MH_CVBOT_SRC_PREVIEW_PREVIEW_UI_H_
#define MH_CVBOT_SRC_PREVIEW_PREVIEW_UI_H_

#include <opencv2/opencv.hpp>
#include "mhtool/mh/mh.h"
#include "./preview_config.h"
#include <QtWidgets/QMainWindow>
#include <QLabel>

class PreviewUI: public QMainWindow {
  Q_OBJECT
 public:
  explicit PreviewUI(QWidget *parent);
 private:
  cv::Mat cacheSnap;
  QLabel *label = nullptr;
};

#endif //MH_CVBOT_SRC_PREVIEW_PREVIEW_UI_H_
