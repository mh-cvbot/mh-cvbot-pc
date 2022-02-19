// // Created by huhua on 2021/9/28.
//

#include <iostream>
#include <mhtool/util/util.h>
#include <stdio.h>
#include "mhtool/mh/mh.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <tchar.h>
#endif

#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383

MH* MH::_inst = nullptr;

std::string MH::MH_MAIN_EXE = "mhmain.exe";
std::string MH::MH_TAB_EXE = "mhtab.exe";

MH *MH::inst() {
  if (_inst == nullptr) {
    _inst = new MH();
  }
  return _inst;
}

bool MH::hasInstalled() {
    return false;
}

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
void QueryKey(HKEY hKey)
{
    TCHAR    achKey[MAX_KEY_LENGTH];   // buffer for subkey name
    DWORD    cbName;                   // size of name string
    TCHAR    achClass[MAX_PATH] = TEXT("");  // buffer for class name
    DWORD    cchClassName = MAX_PATH;  // size of class string
    DWORD    cSubKeys=0;               // number of subkeys
    DWORD    cbMaxSubKey;              // longest subkey size
    DWORD    cchMaxClass;              // longest class string
    DWORD    cValues;              // number of values for key
    DWORD    cchMaxValue;          // longest value name
    DWORD    cbMaxValueData;       // longest value data
    DWORD    cbSecurityDescriptor; // size of security descriptor
    FILETIME ftLastWriteTime;      // last write time

    DWORD i, retCode;

    TCHAR  achValue[MAX_VALUE_NAME];
    DWORD cchValue = MAX_VALUE_NAME;

    // Get the class name and the value count.
    retCode = RegQueryInfoKey(
            hKey,                    // key handle
            achClass,                // buffer for class name
            &cchClassName,           // size of class string
            NULL,                    // reserved
            &cSubKeys,               // number of subkeys
            &cbMaxSubKey,            // longest subkey size
            &cchMaxClass,            // longest class string
            &cValues,                // number of values for this key
            &cchMaxValue,            // longest value name
            &cbMaxValueData,         // longest value data
            &cbSecurityDescriptor,   // security descriptor
            &ftLastWriteTime);       // last write time

    // Enumerate the subkeys, until RegEnumKeyEx fails.

    if (cSubKeys)
    {
        printf( "\nNumber of subkeys: %d\n", cSubKeys);

        for (i=0; i<cSubKeys; i++)
        {
            cbName = MAX_KEY_LENGTH;
            retCode = RegEnumKeyEx(hKey, i,
                                   achKey,
                                   &cbName,
                                   NULL,
                                   NULL,
                                   NULL,
                                   &ftLastWriteTime);
            if (retCode == ERROR_SUCCESS)
            {
                _tprintf(TEXT("(%d) %s\n"), i+1, achKey);
            }
        }
    }

    // Enumerate the key values.

    if (cValues)
    {
        for (i=0, retCode=ERROR_SUCCESS; i<cValues; i++)
        {
            cchValue = MAX_VALUE_NAME;
            achValue[0] = '\0';
            retCode = RegEnumValue(hKey, i,
                                   achValue,
                                   &cchValue,
                                   NULL,
                                   NULL,
                                   NULL,
                                   NULL);

            if (retCode == ERROR_SUCCESS )
            {
                _tprintf(TEXT("(%d) %s\n"), i+1, achValue);
            }
        }
    }
}
#endif

/**
 * can I throw an exception?
 */
std::string MH::getInstallPath() {
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    HKEY rootKey;
    auto rst = RegOpenKeyEx(HKEY_CURRENT_USER,
                            TEXT("Software\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\Compatibility Assistant\\Store"),
                            0, KEY_ENUMERATE_SUB_KEYS | KEY_READ, &rootKey);
    if (rst != ERROR_SUCCESS) {
        throw std::runtime_error("reg open failed");
    }
//
    TCHAR    achKey[MAX_KEY_LENGTH];   // buffer for subkey name
    DWORD    cbName;                   // size of name string
    TCHAR    achClass[MAX_PATH] = TEXT("");  // buffer for class name
    DWORD    cchClassName = MAX_PATH;  // size of class string
    DWORD    cSubKeys=0;               // number of subkeys
    DWORD    cbMaxSubKey;              // longest subkey size
    DWORD    cchMaxClass;              // longest class string
    DWORD    cValues;              // number of values for key
    DWORD    cchMaxValue;          // longest value name
    DWORD    cbMaxValueData;       // longest value data
    DWORD    cbSecurityDescriptor; // size of security descriptor
    FILETIME ftLastWriteTime;      // last write time

    DWORD i, retCode;

    TCHAR  achValue[MAX_VALUE_NAME];
    DWORD cchValue = MAX_VALUE_NAME;

    // Get the class name and the value count.
    retCode = RegQueryInfoKey(
            rootKey,                    // key handle
            achClass,                // buffer for class name
            &cchClassName,           // size of class string
            NULL,                    // reserved
            &cSubKeys,               // number of subkeys
            &cbMaxSubKey,            // longest subkey size
            &cchMaxClass,            // longest class string
            &cValues,                // number of values for this key
            &cchMaxValue,            // longest value name
            &cbMaxValueData,         // longest value data
            &cbSecurityDescriptor,   // security descriptor
            &ftLastWriteTime);       // last write time

    if (cValues)
    {
        printf( "\nNumber of values: %d\n", cValues);

        for (i=0, retCode=ERROR_SUCCESS; i<cValues; i++)
        {
            cchValue = MAX_VALUE_NAME;
            achValue[0] = '\0';
            retCode = RegEnumValue(rootKey, i,
                                   achValue,
                                   &cchValue,
                                   NULL,
                                   NULL,
                                   NULL,
                                   NULL);


            if (retCode == ERROR_SUCCESS )
            {
                if (strEndsWith(std::string(achValue), "mhtab.exe")) {
                    RegCloseKey(rootKey);
                    // ok, remove the mhtab.
                    return boost::filesystem::path(achValue).parent_path().string();
                }
            }
        }
    }

    RegCloseKey(rootKey);
#endif

    return "";
}

MhPath MH::getPath() {
    return MhPath(this->getInstallPath());
}

void MH::start() {
    MhPath path = this->getPath();
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
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
                   this->getInstallPath().c_str(),           // Use parent's starting directory
                   &si,            // Pointer to STARTUPINFO structure
                   &pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
    );
    // Close process and thread handles.
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
#endif
}

int MH::startedCount() {
    return 0;
}

MH::MH(): _pTab(0), _pMain(0), _gameWin(nullptr), _win(nullptr) {

}

void MH::refresh() {
  try {
    // 开始的逻辑怎么写合适？
    auto pMhTab = eb::Process::findByName(MH::MH_TAB_EXE);
    auto pMhMain = eb::Process::findByName(MH::MH_MAIN_EXE);


    if (pMhMain.getPid() == 0) {
      return;
    }

    this->_win = pMhTab.getBiggestWindow();

    auto subWindows = this->_win.getSubWindows();

    this->_gameWin = subWindows[1];

    if (eb::gbk2utf8(this->_win.title) == "梦幻西游 ONLINE") {
      return;
    }

  } catch (std::runtime_error &err) {
    std::cout << "has error: " << err.what() << std::endl;
  }
}

eb::Window *MH::gameWin() {
  return &this->_gameWin;
}

eb::Process *MH::pMain() {
  return &this->_pMain;
}

Result MH::checkHasLogin() {
  this->refresh();
  if (this->gameWin()->getId() == nullptr) {
    return {1, "请开启并登录游戏"};
  }

  if (eb::gbk2utf8(MH::inst()->gameWin()->title) == "梦幻西游 ONLINE") {
    return {1, "没有登录"};
  }
  return {0, ""};
}
