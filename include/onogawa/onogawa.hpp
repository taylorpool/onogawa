#pragma once

#include "sabai/sabai.hpp"

namespace onogawa {
class Point2 : public sabai::StaticVectord<2> {
private:
  static constexpr uint64_t X_INDEX = 0;
  static constexpr uint64_t Y_INDEX = 1;

public:
  Point2(double x, double y);

  constexpr double x() const { return operator()(X_INDEX); }
  constexpr double y() const { return operator()(Y_INDEX); }
  constexpr double &x() { return operator()(X_INDEX); }
  constexpr double &y() { return operator()(Y_INDEX); }
};

class Quaternion {
private:
  static constexpr uint64_t W_INDEX = 0;
  static constexpr uint64_t X_INDEX = 1;
  static constexpr uint64_t Y_INDEX = 2;
  static constexpr uint64_t Z_INDEX = 3;
  sabai::StaticVectord<4> data_;

public:
  Quaternion(double w, double x, double y, double z);

  static Quaternion ew();
  static Quaternion ex();
  static Quaternion ey();
  static Quaternion ez();

  constexpr double w() const { return data_(W_INDEX); }
  constexpr double x() const { return data_(X_INDEX); }
  constexpr double y() const { return data_(Y_INDEX); }
  constexpr double z() const { return data_(Z_INDEX); }
}; // namespace onogawa

Quaternion operator*(const Quaternion &a, const Quaternion &b);
} // namespace onogawa
