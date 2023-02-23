#pragma once

#include "onogawa/compass.hpp"
#include "onogawa/point2.hpp"

namespace onogawa {

template <typename T> struct Pose2 {
  Compass<T> orientation;
  Point2<T> position;

  constexpr Pose2(const Compass<T> &orientation, const Point2<T> &position)
      : orientation(orientation), position(position) {}
};

template <typename T>
constexpr Pose2<T> operator*(const Pose2<T> &a, const Pose2<T> &b) {
  return Pose2(a.orientation * b.orientation,
               a.orientation * b.position + a.position);
}

using Pose2d = Pose2<double>;

} // namespace onogawa
