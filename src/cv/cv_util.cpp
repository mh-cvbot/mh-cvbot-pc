//
// Created by th on 2022/1/30.
//

#include <easybot/easybot.h>
#include <mhtool/cv/cv_util.h>

void mh::cv1::white(const ::cv::_InputArray &in, const ::cv::_OutputArray &out) {
  auto range = eb::HSVRange({0, 0, 0}, {0, 255, 255});
  range.work(in, out);
}
