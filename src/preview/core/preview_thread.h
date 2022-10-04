//
// Created by huhua on 2022/10/3.
//

#ifndef MH_CVBOT_SRC_PREVIEW_CORE_PREVIEW_THREAD_H_
#define MH_CVBOT_SRC_PREVIEW_CORE_PREVIEW_THREAD_H_
#include <QThread>
#include <QObject>
#include <opencv2/opencv.hpp>

class PreviewThread: public QThread {
  Q_OBJECT
 protected:
  void run() override;
 public:
  signals:
      void onPreviewGot(const cv::Mat &mat);
 private:
  cv::Mat cachedSnap;
};
#endif //MH_CVBOT_SRC_PREVIEW_CORE_PREVIEW_THREAD_H_
