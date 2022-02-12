//
// Created by huhua on 2021/8/7.
//

#include <gtest/gtest.h>
#include <qt_windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <opencv2/opencv.hpp>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
// Expect two strings not to be equal.
EXPECT_STRNE("hello", "world");
// Expect equality.
EXPECT_EQ(7 * 6, 42);
}

void printError(PTCHAR msg) {
    DWORD eNum;
    TCHAR sysMsg[256];

    eNum = GetLastError();
    FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                  nullptr, eNum,
                  MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
                  sysMsg, 256, nullptr);

    printf(TEXT("WARNING: %s failed with error %lu(%s)"), msg, eNum, sysMsg);
}


const std::string MH_PROCESS_NAME = "my.exe";

static void ListProcessModules(DWORD pid) {
    HANDLE hModuleSnap = INVALID_HANDLE_VALUE;
    MODULEENTRY32 me32;

    hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);

    if (hModuleSnap == INVALID_HANDLE_VALUE) {
        printError("CreateToolhelp32Snapshot");
        return;
    }

    me32.dwSize = sizeof (MODULEENTRY32);

    if (!Module32First(hModuleSnap, &me32)) {
        printError("Module32First");
        return;
    }

    do {
        printf("\n\n    Module Name: %s", me32.szModule);
        printf("\n    Executable: %s", me32.szExePath);
        printf("\n    Process ID: 0x%08X", me32.th32ProcessID);
        printf("\n    Ref Count (g): 0x%04X", me32.GlblcntUsage);
        printf("\n    Ref Count (p): 0x%04X", me32.ProccntUsage);
        printf("\n    Base Address: 0x%08X", me32.modBaseAddr);
        printf("\n    Base Size:%d", me32.modBaseSize);
    } while (Module32Next(hModuleSnap, &me32));

    CloseHandle(hModuleSnap);
}

void captureAndDisplay(HWND hwnd) {
    auto sourceDc = GetDC(hwnd);
    auto distDc = CreateCompatibleDC(sourceDc);

    auto dstBitmap = CreateCompatibleBitmap(sourceDc, 0, 0);

    SelectObject(distDc, dstBitmap);

    BitBlt(distDc, 0, 0, 200, 200, sourceDc, 0, 0, SRCCOPY);

    RECT  windowSize;
    GetClientRect(hwnd, &windowSize);
    auto height = windowSize.bottom;
    auto width = windowSize.right;

    cv::Mat mat;
    mat.create(height, width, CV_8UC4);
    // can we convert it?

    BITMAPINFOHEADER bi;

    GetDIBits(distDc, dstBitmap, 0, height, mat.data, (BITMAPINFO *)&bi, DIB_RGB_COLORS);

    DeleteDC(distDc);
    cv::imshow("test", mat);
    cv::waitKey(0);
}

// https://docs.microsoft.com/en-us/windows/win32/toolhelp/taking-a-snapshot-and-viewing-processes
TEST(HelloTest, EnumProgess) {
    auto thHandler = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    std::cout << "thHandler: " << thHandler << std::endl;
    if (thHandler == INVALID_HANDLE_VALUE) {
        printError(TEXT("CreateToolhelp32Snapshot failed"));
        return;
    }

    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof (PROCESSENTRY32);

    if (!Process32First(thHandler, &pe32)) {
        printError(TEXT("Process32First Failed"));
        CloseHandle(thHandler);
        return;
    }

    do {
        if (MH_PROCESS_NAME.compare(pe32.szExeFile) == 0) {
            printf("\n\n================================================\n");
            printf("process name %s", pe32.szExeFile);

            DWORD priorityClass;
            HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pe32.th32ProcessID);
            if (hProcess == nullptr) {
                printError("OpenProcess");
                break;
            }
            priorityClass = GetPriorityClass(hProcess);
            if (!priorityClass) {
                printError("GetPriorityClass");
                CloseHandle(hProcess);
                break;
            }

            printf("\n  Process Id = 0x%08X, %d", pe32.th32ProcessID, pe32.th32ProcessID);
            printf("\n  Thread Count = %d", pe32.cntThreads);
            printf("\n  Parent process ID = 0x%08X, %d", pe32.th32ParentProcessID, pe32.th32ParentProcessID);
            printf("\n  Priority Base = %d", pe32.pcPriClassBase);
            printf("\n  Priority class = %d", priorityClass);

            CloseHandle(hProcess);
            ListProcessModules(pe32.th32ProcessID);
        }
        // ok, let's try open it.
    } while(Process32Next(thHandler, &pe32));

    CloseHandle(thHandler);
}

