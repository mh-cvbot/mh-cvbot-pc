//
// Created by huhua on 2022/2/16.
//

#include <mhtool/comm/log.h>
#include <QDebug>

void Log::i(const std::string& str) {
  Log::i(QString(str.c_str()));
}

void Log::i(const QString &str) {
  qDebug() << str;
}

void Log::i(const char *str) {
  qDebug() << str;
}
