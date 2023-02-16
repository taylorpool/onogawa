#pragma once

namespace onogawa {

struct Compass {
  double x;
  double y;

  constexpr Compass(double x, double y) : x(x), y(y) {}

  constexpr static Compass ex() { return Compass(1.0, 0.0); }
  constexpr static Compass ey() { return Compass(0.0, 1.0); }
};

constexpr Compass operator*(const Compass &a, const Compass &b) {
  return Compass(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}

struct Point2 {
  double x;
  double y;

  constexpr Point2(double x, double y) : x(x), y(y) {}

  constexpr static Point2 ex() { return Point2(1.0, 0.0); }
  constexpr static Point2 ey() { return Point2(0.0, 1.0); }
};

constexpr Point2 operator+(const Point2 &a, const Point2 &b) {
  return Point2(a.x + b.x, a.y + b.y);
}

constexpr Point2 operator*(const Compass &compass, const Point2 &point) {
  return Point2(compass.x * point.x - compass.y * point.y,
                compass.x * point.y - compass.y * point.x);
}

struct Pose2 {
  Compass orientation;
  Point2 position;

  constexpr Pose2(const Compass &orientation, const Point2 &position)
      : orientation(orientation), position(position) {}
};

constexpr Pose2 operator*(const Pose2 &a, const Pose2 &b) {
  return Pose2(a.orientation * b.orientation,
               a.orientation * b.position + a.position);
}

struct Quaternion {
  double w;
  double x;
  double y;
  double z;

  constexpr Quaternion(double w, double x, double y, double z)
      : w(w), x(x), y(y), z(z) {}

  constexpr static Quaternion ew() { return Quaternion(1.0, 0.0, 0.0, 0.0); };
  constexpr static Quaternion ex() { return Quaternion(0.0, 1.0, 0.0, 0.0); };
  constexpr static Quaternion ey() { return Quaternion(0.0, 0.0, 1.0, 0.0); };
  constexpr static Quaternion ez() { return Quaternion(0.0, 0.0, 0.0, 1.0); };
};

constexpr Quaternion operator*(const Quaternion &a, const Quaternion &b) {
  return Quaternion(a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z,
                    a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,
                    a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x,
                    a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w);
}

struct Point3 {
  double x;
  double y;
  double z;

  constexpr Point3(double x, double y, double z) : x(x), y(y), z(z) {}

  constexpr static Point3 ex() { return Point3(1.0, 0.0, 0.0); }
  constexpr static Point3 ey() { return Point3(0.0, 1.0, 0.0); }
  constexpr static Point3 ez() { return Point3(0.0, 0.0, 1.0); }
};

constexpr Point3 operator+(const Point3 &a, const Point3 &b) {
  return Point3(a.x + b.x, a.y + b.y, a.z + b.z);
}

constexpr Point3 operator*(const Quaternion &q, const Point3 &point) {
  const double s = 2.0 / (q.w * q.w + q.x * q.x + q.y * q.y + q.z * q.z);

  const double xs = q.x * s;
  const double ys = q.y * s;
  const double zs = q.z * s;

  const double wxs = q.w * xs;
  const double wys = q.w * ys;
  const double wzs = q.w * zs;

  const double xxs = q.x * xs;
  const double xys = q.x * ys;
  const double xzs = q.x * zs;

  const double yys = q.y * ys;
  const double yzs = q.y * zs;

  const double zzs = q.z * zs;

  return Point3(
      (1 - yys - zzs) * point.x + (xys - wzs) * point.y + (xzs + wys) * point.z,
      (xys + wzs) * point.x + (1 - xxs - zzs) * point.y + (yzs - wxs) * point.z,
      (xzs - wys) * point.x + (yzs + wxs) * point.y +
          (1 - xxs - yys) * point.z);
}

struct Pose3 {
  Quaternion orientation;
  Point3 position;

  constexpr Pose3(const Quaternion &orientation, const Point3 &position)
      : orientation(orientation), position(position) {}
};

constexpr Pose3 operator*(const Pose3 &a, const Pose3 &b) {
  return Pose3(a.orientation * b.orientation,
               a.orientation * b.position + a.position);
}

} // namespace onogawa
