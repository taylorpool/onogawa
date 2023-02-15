#include "onogawa/onogawa.hpp"

namespace onogawa {
Point2::Point2(double x, double y) {
  operator()(X_INDEX) = x;
  operator()(Y_INDEX) = y;
}

Quaternion::Quaternion(double w, double x, double y, double z) {
  data_(W_INDEX) = w;
  data_(X_INDEX) = x;
  data_(Y_INDEX) = y;
  data_(Z_INDEX) = z;
}

Quaternion operator*(const Quaternion &a, const Quaternion &b) {
  return Quaternion(
      a.w() * b.w() - a.x() * b.x() - a.y() * b.y() - a.z() * b.z(),
      a.w() * b.x() + a.x() * b.w() + a.y() * b.z() - a.z() * b.y(),
      a.w() * b.y() - a.x() * b.z() + a.y() * b.w() + a.z() * b.x(),
      a.w() * b.z() + a.x() * b.y() - a.y() * b.x() + a.z() * b.w());
}

Quaternion Quaternion::ew() { return Quaternion(1.0, 0.0, 0.0, 0.0); }
Quaternion Quaternion::ex() { return Quaternion(0.0, 1.0, 0.0, 0.0); }
Quaternion Quaternion::ey() { return Quaternion(0.0, 0.0, 1.0, 0.0); }
Quaternion Quaternion::ez() { return Quaternion(0.0, 0.0, 0.0, 1.0); }

} // namespace onogawa
