#include "onogawa/onogawa.hpp"

namespace onogawa {
Point2::Point2(double x, double y) {
  operator()(X_INDEX) = x;
  operator()(Y_INDEX) = y;
}

} // namespace onogawa
