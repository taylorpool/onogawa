#pragma once

namespace onogawa {

template <typename T> struct Compass {
  T x;
  T y;

  constexpr Compass(T x, T y) : x(x), y(y) {}

  constexpr static Compass ex() { return Compass(1.0, 0.0); }
  constexpr static Compass ey() { return Compass(0.0, 1.0); }
};

template <typename T>
constexpr Compass<T> operator*(const Compass<T> &a, const Compass<T> &b) {
  return Compass(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}

using Compassd = Compass<double>;

} // namespace onogawa
