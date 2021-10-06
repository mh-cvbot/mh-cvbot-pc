//
// Created by huhua on 2021/10/3.
//

#include <mh-tool/util/util.h>

bool strEndsWith(const std::string &str1, const std::string &str2) {
    if (str1.length() >= str2.length()) {
        return (0 == str1.compare (str1.length() - str2.length(), str2.length(), str2));
    } else {
        return false;
    }
}
