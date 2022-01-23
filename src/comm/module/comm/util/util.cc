//
// Created by huhua on 2021/10/3.
//

#include <mhtool/util/util.h>

bool strEndsWith(const std::string &str1, const std::string &str2) {
    if (str1.length() >= str2.length()) {
        return (0 == str1.compare (str1.length() - str2.length(), str2.length(), str2));
    } else {
        return false;
    }
}

unsigned __int64 currentTimeMilliseconds() {
    unsigned __int64 now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    return now;
}
