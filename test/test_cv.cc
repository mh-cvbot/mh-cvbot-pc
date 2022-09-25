//
// Created by huhua on 2022/1/24.
//
#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>
#include "module/cv/cv.h"
#include <mhtool/comm/module/pos_indicator/pos_indicator_state.h>
#include "./cv_info.h"

TEST(testCV, posIndicatorState) {
  auto img = cv::imread("./test_data/0.bmp");
  ASSERT_TRUE(!img.empty());
  mh::PosIndicatorState state;
  auto rst = mh::Cv::posIndicatorState(img, &state);
  ASSERT_TRUE(rst);
  ASSERT_EQ(state, mh::PosIndicatorState::MIDDLE);
}

static void testPosIndicator(const std::string &name, mh::PosIndicator pi) {
  auto img = cv::imread("./test_data/" + name);
//  cv::imshow("img", img);
//  cv::waitKey(0);
  ASSERT_TRUE(!img.empty());
  mh::PosIndicator _pi;
  auto rst = mh::Cv::posIndicator(img, &_pi);
  std::cout << "_pi: " << _pi << std::endl;
  ASSERT_TRUE(rst);
  ASSERT_EQ(_pi, pi);
}

static void testItem(const std::string &name, CvInfo info) {
  auto img = cv::imread("./test_data/" + name);
  ASSERT_TRUE(!img.empty());

  mh::PosIndicator _pi;
  auto rst = mh::Cv::posIndicator(img, &_pi);
//  std::cout << "_pi: " << _pi << std::endl;
  ASSERT_TRUE(rst);
  ASSERT_EQ(_pi.name, info.name);
  ASSERT_EQ(_pi.pos.x(), info.x);
  ASSERT_EQ(_pi.pos.y(), info.y);
}

TEST(testCV, posIndicator) {
  testItem("0.bmp", {"桃源村", 18, 78, {-1}});
//  testPosIndicator("0.bmp", {"桃源村", {18, 78}, mh::PosIndicatorState::MIDDLE});
////  testPosIndicator("1.bmp", {"桃源村", {32, 76}, mh::PosIndicatorState::MIDDLE});
////  testPosIndicator("mac_0.bmp", {"桃源村", {53, 81}, mh::PosIndicatorState::MIDDLE});
//  testPosIndicator("3.bmp", {"长安城", {449, 173}, mh::PosIndicatorState::MIDDLE});
}
