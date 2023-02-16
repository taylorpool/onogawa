#pragma once

#include "sabai/sabai.hpp"

namespace onogawa {

class Complex {
private:
  double real_;
  double imaginary_;

public:
  constexpr Complex(double real, double imaginary)
      : real_(real), imaginary_(imaginary) {}
};

class Point2 {
private:
  double x_;
  double y_;

public:
  constexpr Point2(double x, double y) : x_(x), y_(y) {}

  constexpr double x() const { return x_; }
  constexpr double y() const { return y_; }
  constexpr double &x() { return x_; }
  constexpr double &y() { return y_; }
};

class Quaternion {
private:
  static constexpr uint64_t W_INDEX = 0;
  static constexpr uint64_t X_INDEX = 1;
  static constexpr uint64_t Y_INDEX = 2;
  static constexpr uint64_t Z_INDEX = 3;
  sabai::StaticVectord<4> data_;

public:
  constexpr Quaternion(double w, double x, double y, double z) {
    data_(W_INDEX) = w;
    data_(X_INDEX) = x;
    data_(Y_INDEX) = y;
    data_(Z_INDEX) = z;
  }

  constexpr static Quaternion ew() { return Quaternion(1.0, 0.0, 0.0, 0.0); };
  constexpr static Quaternion ex() { return Quaternion(0.0, 1.0, 0.0, 0.0); };
  constexpr static Quaternion ey() { return Quaternion(0.0, 0.0, 1.0, 0.0); };
  constexpr static Quaternion ez() { return Quaternion(0.0, 0.0, 0.0, 1.0); };

  constexpr double w() const { return data_(W_INDEX); }
  constexpr double x() const { return data_(X_INDEX); }
  constexpr double y() const { return data_(Y_INDEX); }
  constexpr double z() const { return data_(Z_INDEX); }
};

Quaternion operator*(const Quaternion &a, const Quaternion &b);

class Point3 {
private:
  double x_;
  double y_;
  double z_;

public:
  constexpr Point3(double x, double y, double z) : x_(x), y_(y), z_(z) {}

  constexpr double x() const { return x_; }
  constexpr double y() const { return y_; }
  constexpr double z() const { return z_; }
  constexpr double &x() { return x_; }
  constexpr double &y() { return y_; }
  constexpr double &z() { return z_; }
};

constexpr Point3 operator*(const Quaternion &q, const Point3 &point) {
  const double s =
      2.0 / (q.w() * q.w() + q.x() * q.x() + q.y() * q.y() + q.z() * q.z());

  const double xs = q.x() * s;
  const double ys = q.y() * s;
  const double zs = q.z() * s;

  const double wxs = q.w() * xs;
  const double wys = q.w() * ys;
  const double wzs = q.w() * zs;

  const double xxs = q.x() * xs;
  const double xys = q.x() * ys;
  const double xzs = q.x() * zs;

  const double yys = q.y() * ys;
  const double yzs = q.y() * zs;

  const double zzs = q.z() * zs;

  return Point3((1 - yys - zzs) * point.x() + (xys - wzs) * point.y() +
                    (xzs + wys) * point.z(),
                (xys + wzs) * point.x() + (1 - xxs - zzs) * point.y() +
                    (yzs - wxs) * point.z(),
                (xzs - wys) * point.x() + (yzs + wxs) * point.y() +
                    (1 - xxs - yys) * point.z());
}

} // namespace onogawa
