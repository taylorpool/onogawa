#include "onogawa/onogawa.hpp"
#include <gtest/gtest.h>

TEST(Hello, World) { ASSERT_TRUE(true); }

class Point2Fixture : public ::testing::Test {
protected:
  double x;
  double y;
  double new_x;
  double new_y;
  onogawa::Point2 point;
  Point2Fixture() : x(0.0), y(1.0), new_x(2.0), new_y(3.0), point(x, y) {}
};

TEST_F(Point2Fixture, CheckX) { ASSERT_EQ(point.x(), x); }
TEST_F(Point2Fixture, CheckY) { ASSERT_EQ(point.y(), y); }
TEST_F(Point2Fixture, UpdateX) {
  point.x() = new_x;
  ASSERT_EQ(point.x(), new_x);
}
TEST_F(Point2Fixture, UpdateY) {
  point.y() = new_y;
  ASSERT_EQ(point.y(), new_y);
}
