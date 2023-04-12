#pragma once

#include "onogawa/point3.hpp"
#include "onogawa/quaternion.hpp"
#include "sabai/sabai.hpp"

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

template <typename T>
constexpr Pose3<T> Exp(const sabai::StaticVector<T, 3> &angularVelocity,
                       const sabai::StaticVector<T, 3> &linearVelocity) {
  const T theta;
  if (sabai::norm(angularVelocity) == 0.0) {

    theta = sabai::norm(linearVelocity);
  } else {
    theta = sabai::norm(angularVelocity);
  }

  const sabai::StaticVector<T, 3> hatv;
  const sabai::StaticVector<T, 3> hathatv;

  return Pose3<T>(Exp(angularVelocity),
                  theta * linearVelocity + (1.0 - std::cos(theta)) * hatv +
                      (theta - std::sin(theta) * hathatv));
}

} // namespace onogawa