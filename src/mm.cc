//
// Created by huhua on 2021/9/28.
//

#include <mh-tool/mm.h>

bool MM::hasInstalled() {
    return false;
}

std::string MM::getMainExePath() {
    // ok, let's impl this.
    // First method: search the driver. Not good?

    // Second method. search the regex? Ok, let's try this method
//    const auto REG_PATH = "HKEY_CURRENT_USER\Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Compatibility Assistant\Store";

    return std::string();
}
