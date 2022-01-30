//
// Created by th on 2022/1/30.
//

#include <mhtool/cv/cv_util.h>
#include <easybot/easybot.h>

void mh::cv::white(const ::cv::_InputArray &in, const ::cv::_OutputArray &out) {
  auto range = eb::HSVRange({0, 0, 0}, {0, 255, 255});
  range.work(in, out);
}
