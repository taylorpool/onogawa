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
} // namespace onogawa
