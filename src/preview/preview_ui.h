//
// Created by huhua on 2022/9/24.
//

#ifndef MH_CVBOT_SRC_PREVIEW_PREVIEW_UI_H_
#define MH_CVBOT_SRC_PREVIEW_PREVIEW_UI_H_

#include <QtWidgets>
#include <opencv2/opencv.hpp>
#include "mhtool/mh/mh.h"
#include "./core/preview_thread.h"

class PreviewUI: public QMainWindow {
  Q_OBJECT
 public:
  PreviewUI();
  ~PreviewUI() override;
  public slots:
  void preview(const cv::Mat &mat);
 private:
  cv::Mat cacheSnap;
  QLabel *label;
  PreviewThread *previewThread;
};
#endif //MH_CVBOT_SRC_PREVIEW_PREVIEW_UI_H_
