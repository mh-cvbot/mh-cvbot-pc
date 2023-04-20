//
// Created by huhua on 2021/8/7.
//
#include <QApplication>

#include <iostream>
#include "../preview/preview_ui.h"
#include "../app/App.h"

int main(int argc, char **argv) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QApplication q(argc, argv);

//  PreviewUI preview;
//  preview.show();
  App app;
  app.show();

  return QApplication::exec();
}