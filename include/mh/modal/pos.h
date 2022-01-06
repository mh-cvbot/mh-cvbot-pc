//
// Created by huhua on 2022/1/4.
//

#ifndef MH_TOOL_POS_H
#define MH_TOOL_POS_H
#include <string>
#include <utility>

namespace mh {
namespace modal {
class Pos {
private:
    int x;
    int y;
    std::string name;

public:
    Pos(int x, int y, std::string name): x(x), y(y), name(std::move(name)) {};
};
}
}
#endif //MH_TOOL_POS_H
