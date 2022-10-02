//
// Created by huhua on 2021/8/7.
//
#include <QApplication>

#include <iostream>
#include "./preview/preview_ui.h"

int main(int argc, char **argv) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QApplication q(argc, argv);

//  PreviewUI preview;
//  preview.show();

  return QApplication::exec();
}