#pragma once

#include "onogawa/point3.hpp"
#include "onogawa/quaternion.hpp"

namespace onogawa {

template <typename T> struct Pose3 {
  Quaternion<T> orientation;
  Point3<T> position;

  constexpr Pose3(const Quaternion<T> &orientation, const Point3<T> &position)
      : orientation(orientation), position(position) {}
};

template <typename T>
constexpr Pose3<T> operator*(const Pose3<T> &a, const Pose3<T> &b) {
  return Pose3(a.orientation * b.orientation,
               a.orientation * b.position + a.position);
}

using Pose3d = Pose3<double>;

} // namespace onogawa