#pragma once

namespace onogawa {

template <typename T> struct Quaternion {
  T w;
  T x;
  T y;
  T z;

  constexpr Quaternion(T w, T x, T y, T z) : w(w), x(x), y(y), z(z) {}

  constexpr static Quaternion ew() { return Quaternion(1.0, 0.0, 0.0, 0.0); };
  constexpr static Quaternion ex() { return Quaternion(0.0, 1.0, 0.0, 0.0); };
  constexpr static Quaternion ey() { return Quaternion(0.0, 0.0, 1.0, 0.0); };
  constexpr static Quaternion ez() { return Quaternion(0.0, 0.0, 0.0, 1.0); };
};

template <typename T>
constexpr Quaternion<T> operator*(const Quaternion<T> &a,
                                  const Quaternion<T> &b) {
  return Quaternion(a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z,
                    a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,
                    a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x,
                    a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w);
}

using Quaterniond = Quaternion<double>;

} // namespace onogawa