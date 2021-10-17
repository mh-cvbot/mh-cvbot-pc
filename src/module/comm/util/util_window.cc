//
// Created by huhua on 2021/8/8.
//

#include <mh-tool/util/util_window.h>
#include <mh-tool/util/util.h>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

void windowScreenshot(eb::Window *window) {
    cv::Mat out;
    window->screenshot(out);
    std::string currentTime = std::to_string(currentTimeMilliseconds());
    boost::filesystem::path savePath = boost::filesystem::current_path() / "runtime" / "screenshot" / (currentTime + ".bmp");
    std::cout << "savePath: " << savePath << std::endl;
    cv::imwrite(savePath.string(), out);
    std::cout << "save success" << std::endl;
}
