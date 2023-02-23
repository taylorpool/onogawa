#pragma once

#include "onogawa/compass.hpp"

namespace onogawa {

template <typename T> struct Point2 {
  T x;
  T y;

  constexpr Point2(T x, T y) : x(x), y(y) {}

  constexpr static Point2 ex() { return Point2(1.0, 0.0); }
  constexpr static Point2 ey() { return Point2(0.0, 1.0); }
};

template <typename T>
constexpr Point2<T> operator+(const Point2<T> &a, const Point2<T> &b) {
  return Point2(a.x + b.x, a.y + b.y);
}

template <typename T>
constexpr Point2<T> operator*(const Compass<T> &compass,
                              const Point2<T> &point) {
  return Point2(compass.x * point.x - compass.y * point.y,
                compass.x * point.y - compass.y * point.x);
}

using Point2d = Point2<double>;

} // namespace onogawa