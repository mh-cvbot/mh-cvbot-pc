//
// Created by huhua on 2021/9/28.
//

#include <gtest/gtest.h>
#include <iostream>
#include <algorithm>
//#include <boost/algorithm/string/replace.hpp>
#include <Windows.h>
#include "mhtool/comm/mh/mh.h"
#include "mhtool/comm/mh/mh_path.h"

static void startApp1(MH& mh) {
    MhPath path = mh.getPath();
    // additional information
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    // set the size of the structures
    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

    // start the program up
    CreateProcess( path.launcherPath().c_str(),   // the path
                   "",        // Command line
                   NULL,           // Process handle not inheritable
                   NULL,           // Thread handle not inheritable
                   FALSE,          // Set handle inheritance to FALSE
                   0,              // No creation flags
                   NULL,           // Use parent's environment block
                   mh.getInstallPath().c_str(),           // Use parent's starting directory
                   &si,            // Pointer to STARTUPINFO structure
                   &pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
    );
    // Close process and thread handles.
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
}

TEST(test_mm, isInstalled) {
    MH mh;
    startApp1(mh);
//    std::cout << mm.getInstallPath() << std::endl;
//    std::cout << mm.getPath().launcherPath() << std::endl;
//    auto myPath = mm.getPath().launcherPath();
//    boost::replace_all(myPath, " ", "^ ");
//    boost::replace_all(myPath, "(", "^(");
//    boost::replace_all(myPath, ")", "^)");
////    std::replace(myPath.begin(), myPath.end(), " ", "^ ");
//    std::cout << "myPath: " << myPath << std::endl;
//    system(myPath.c_str());
    getchar();
}