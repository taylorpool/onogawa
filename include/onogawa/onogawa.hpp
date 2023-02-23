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

template <typename T> struct Pose2 {
  Compass<T> orientation;
  Point2<T> position;

  constexpr Pose2(const Compass<T> &orientation, const Point2<T> &position)
      : orientation(orientation), position(position) {}
};

template <typename T>
constexpr Pose2<T> operator*(const Pose2<T> &a, const Pose2<T> &b) {
  return Pose2(a.orientation * b.orientation,
               a.orientation * b.position + a.position);
}

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

template <typename T> struct Pose3 {
  Quaternion<T> orientation;
  Point3<T> position;

  constexpr Pose3(const Quaternion<T> &orientation, const Point3<T> &position)
      : orientation(orientation), position(position) {}
};

template <typename T>
constexpr Pose3<T> operator*(const Pose3<T> &a, const Pose3<T> &b) {
  return Pose3(a.orientation * b.orientation,
               a.orientation * b.position + a.position);
}

using Compassd = Compass<double>;
using Point2d = Point2<double>;
using Pose2d = Pose2<double>;
using Quaterniond = Quaternion<double>;
using Point3d = Point3<double>;
using Pose3d = Pose3<double>;

} // namespace onogawa
