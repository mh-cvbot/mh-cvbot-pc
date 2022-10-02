//
// Created by huhua on 2022/9/24.
//

//#include <QStatusBar>
#include <QtWidgets>
#include "./preview_ui.h"
#include <mhtool/util/util_qt.h>
static int PREVIEW_CONFIG_INIT_WIDTH = 800;
static int PREVIEW_CONFIG_INIT_HEIGHT = 600;

PreviewUI::PreviewUI(): label(new QLabel), previewThread(new PreviewThread) {
  this->resize(PREVIEW_CONFIG_INIT_WIDTH, PREVIEW_CONFIG_INIT_HEIGHT);
  setCentralWidget(label);
  QObject::connect(previewThread, &PreviewThread::onPreviewGot, this,
                   &PreviewUI::preview, Qt::BlockingQueuedConnection);
  previewThread->start();
}

void PreviewUI::preview(const cv::Mat& mat) {
//  std::cout << "mat: " << mat.size() << std::endl;
  if (this->width() != mat.size().width || this->height() != mat.size().height) {
    this->resize(mat.size().width, mat.size().height);
  }
  cv::Mat out;
  cv::cvtColor(mat, out, cv::COLOR_BGR2RGB);
//  statusBar()->showMessage(QString("size: %1-%2").arg(mat.size().width, mat.size().height));
  auto qImage = mat2QImage(out);
  auto qPixmap = QPixmap::fromImage(qImage);
  label->setPixmap(qPixmap);
}

PreviewUI::~PreviewUI() {
  if (!previewThread->isFinished()) {
    previewThread->quit();
  }
}

void PreviewThread::run() {
  std::cout << "PreviewThread::run() called" << std::endl;
  auto win = mh::MH::inst()->gameWin();

  while (true) {
    if (isFinished()) {
      break;
    }
    cv::Mat mat;
    win->screenshot(mat, 2);
//    std::cout << "emit called" << std::endl;
    emit onPreviewGot(mat);
  }
}