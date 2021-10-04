//
// Created by huhua on 2021/10/4.
//

#ifndef MH_TOOL_ACCOUNT_H
#define MH_TOOL_ACCOUNT_H
#include <string>

/**
 * 完了一个账号可以在多个服务器登录啊。怎么弄？
 */
class Account {
public:
    std::string account;
    std::string pwd;
};
#endif //MH_TOOL_ACCOUNT_H
