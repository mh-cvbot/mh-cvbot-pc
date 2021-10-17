//
// Created by huhua on 2021/10/17.
//

#include <mh-tool/module/runtime/runtime.h>
#include <mh-tool/util/util.h>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

namespace runtime {
    void screenshot(eb::Window *window) {
        cv::Mat out;
        window->screenshot(out);
        std::string currentTime = std::to_string(currentTimeMilliseconds());
        boost::filesystem::path savePath = boost::filesystem::current_path() / "runtime" / "screenshot" / (currentTime + ".bmp");
        cv::imwrite(savePath.string(), out);
        std::cout << "save success" << std::endl;
    }
}

