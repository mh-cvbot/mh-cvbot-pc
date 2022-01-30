//
// Created by huhua on 2022/1/24.
//
#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>
#include <mhtool/cv.h>
#include <mhtool/comm/pos_indicator/pos_indicator_state.h>

TEST(testCV, posIndicatorState) {
  auto img = cv::imread("./test_data/0.bmp");
  ASSERT_TRUE(!img.empty());
  mh::PosIndicatorState state;
  auto rst = mh::cv::posIndicatorState(img, &state);
  ASSERT_TRUE(rst);
  ASSERT_EQ(state, mh::PosIndicatorState::MIDDLE);
}

TEST(testCV, posIndicator) {
  auto img = cv::imread("./test_data/0.bmp");
  ASSERT_TRUE(!img.empty());
  mh::PosIndicator pi;
  auto rst = mh::cv::posIndicator(img, &pi);
  ASSERT_TRUE(rst);
  ASSERT_EQ(pi.state, mh::PosIndicatorState::MIDDLE);
  ASSERT_EQ(pi.name, "桃源村");
  ASSERT_EQ(pi.pos, cv::Point2i(18, 78));
}
