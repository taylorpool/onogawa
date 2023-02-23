#pragma once

#include "onogawa/quaternion.hpp"

namespace onogawa {

template <typename T> struct Point3 {
  T x;
  T y;
  T z;

  constexpr Point3(T x, T y, T z) : x(x), y(y), z(z) {}

  constexpr static Point3 ex() { return Point3(1.0, 0.0, 0.0); }
  constexpr static Point3 ey() { return Point3(0.0, 1.0, 0.0); }
  constexpr static Point3 ez() { return Point3(0.0, 0.0, 1.0); }
};

template <typename T>
constexpr Point3<T> operator+(const Point3<T> &a, const Point3<T> &b) {
  return Point3(a.x + b.x, a.y + b.y, a.z + b.z);
}

template <typename T>
constexpr Point3<T> operator*(const Quaternion<T> &q, const Point3<T> &point) {
  const T s = 2.0 / (q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z);

  const T xs = q.x * s;
  const T ys = q.y * s;
  const T zs = q.z * s;

  const T wxs = q.w * xs;
  const T wys = q.w * ys;
  const T wzs = q.w * zs;

  const T xxs = q.x * xs;
  const T xys = q.x * ys;
  const T xzs = q.x * zs;

  const T yys = q.y * ys;
  const T yzs = q.y * zs;

  const T zzs = q.z * zs;

  return Point3(
      (1 - yys - zzs) * point.x + (xys - wzs) * point.y + (xzs + wys) * point.z,
      (xys + wzs) * point.x + (1 - xxs - zzs) * point.y + (yzs - wxs) * point.z,
      (xzs - wys) * point.x + (yzs + wxs) * point.y +
          (1 - xxs - yys) * point.z);
}

using Point3d = Point3<double>;

} // namespace onogawa
