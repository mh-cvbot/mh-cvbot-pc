//
// Created by huhua on 2021/10/17.
//

#ifndef MH_TOOL_CV_IMG_H
#define MH_TOOL_CV_IMG_H

namespace mt {
    namespace cv {
        class CVImg {
        private:
            cv::Mat _origin;

        public:
            CVImg(cv::Mat origin);
        };
    }
}

#endif //MH_TOOL_CV_IMG_H
