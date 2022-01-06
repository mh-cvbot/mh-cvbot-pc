//
// Created by huhua on 2022/1/4.
//

#ifndef MH_TOOL_IMG_H
#define MH_TOOL_IMG_H
#include <string>

namespace mh {
    namespace cv {
// should you go somewhere else?
        class Img {
        private:
            cv::Mat img;

        public:
            static Img createByPath(const std::string& path);
        };
    }
}
#endif //MH_TOOL_IMG_H
