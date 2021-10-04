//
// Created by huhua on 2021/9/27.
//

#include <mh-tool/util_qt.h>


std::string toString(const QPoint &p) {
    return "QPoint(" + std::to_string(p.x()) + ", " + std::to_string(p.y()) + ")";
}
