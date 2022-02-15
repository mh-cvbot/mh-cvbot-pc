//
// Created by huhua on 2021/10/5.
//

#include "log_view.h"
#include <QListView>
#include <QStringListModel>

void TaskLogView::clear() {
  _logs.clear();
}

void TaskLogView::add(const std::string& log) {
  _logs.append(QString(log.c_str()));
}

TaskLogView::TaskLogView(QWidget *parent): QWidget(parent) {
  auto *listView = new QListView(this);
  auto *stringListModel = new QStringListModel();
  stringListModel->setStringList(_logs);
  listView->setModel(stringListModel);
}

void TaskLogView::addError(const std::string &log) {
  this->add(log);
}
