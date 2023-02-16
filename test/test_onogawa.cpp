#include "onogawa/onogawa.hpp"
#include <gtest/gtest.h>

class CompassFixture : public ::testing::Test {
protected:
  double x;
  double y;
  onogawa::Compass compass;

  CompassFixture() : x(1.0), y(0.0), compass(x, y) {}
};

TEST_F(CompassFixture, CheckX) { ASSERT_EQ(compass.x, x); }
TEST_F(CompassFixture, CheckY) { ASSERT_EQ(compass.y, y); }

class CompassXCompassY : public ::testing::Test {
protected:
  onogawa::Compass a;
  onogawa::Compass b;
  onogawa::Compass c;

  CompassXCompassY()
      : a(onogawa::Compass::ex()), b(onogawa::Compass::ey()), c(a * b) {}
};

TEST_F(CompassXCompassY, CheckX) { ASSERT_NEAR(c.x, b.x, 1e-14); }
TEST_F(CompassXCompassY, CheckY) { ASSERT_NEAR(c.y, b.y, 1e-14); }

class CompassNegXCompassY : public ::testing::Test {
protected:
  onogawa::Compass a;
  onogawa::Compass b;
  onogawa::Compass c;

  CompassNegXCompassY() : a(-1.0, 0.0), b(onogawa::Compass::ey()), c(a * b) {}
};

TEST_F(CompassNegXCompassY, CheckX) { ASSERT_NEAR(c.x, b.x, 1e-14); }
TEST_F(CompassNegXCompassY, CheckY) { ASSERT_NEAR(c.y, -b.y, 1e-14); }

class CompassXPointX : public ::testing::Test {
protected:
  onogawa::Compass c;
  onogawa::Point2 p;
  onogawa::Point2 result;

  CompassXPointX()
      : c(onogawa::Compass::ex()), p(onogawa::Point2::ex()), result(c * p) {}
};

TEST_F(CompassXPointX, CheckX) { ASSERT_NEAR(result.x, p.x, 1e-14); }
TEST_F(CompassXPointX, CheckY) { ASSERT_NEAR(result.y, p.y, 1e-14); }

class Point2Fixture : public ::testing::Test {
protected:
  double x;
  double y;
  double new_x;
  double new_y;
  onogawa::Point2 point;
  Point2Fixture() : x(0.0), y(1.0), new_x(2.0), new_y(3.0), point(x, y) {}
};

TEST_F(Point2Fixture, CheckX) { ASSERT_EQ(point.x, x); }
TEST_F(Point2Fixture, CheckY) { ASSERT_EQ(point.y, y); }
TEST_F(Point2Fixture, UpdateX) {
  point.x = new_x;
  ASSERT_EQ(point.x, new_x);
}
TEST_F(Point2Fixture, UpdateY) {
  point.y = new_y;
  ASSERT_EQ(point.y, new_y);
}

class Point2PlusPoint2 : public ::testing::Test {
protected:
  onogawa::Point2 a;
  onogawa::Point2 b;
  onogawa::Point2 c;

  Point2PlusPoint2()
      : a(onogawa::Point2::ex()), b(onogawa::Point2::ey()), c(a + b) {}
};

TEST_F(Point2PlusPoint2, CheckX) { ASSERT_NEAR(c.x, a.x + b.x, 1e-14); }
TEST_F(Point2PlusPoint2, CheckY) { ASSERT_NEAR(c.y, a.y + b.y, 1e-14); }

class Point3Fixture : public ::testing::Test {
protected:
  double x;
  double y;
  double z;
  double new_x;
  double new_y;
  double new_z;

  onogawa::Point3 point;

  Point3Fixture()
      : x(1.0), y(2.0), z(3.0), new_x(4.0), new_y(5.0), new_z(6.0),
        point(x, y, z) {}
};

TEST_F(Point3Fixture, CheckX) { ASSERT_EQ(point.x, x); }
TEST_F(Point3Fixture, CheckY) { ASSERT_EQ(point.y, y); }
TEST_F(Point3Fixture, CheckZ) { ASSERT_EQ(point.z, z); }
TEST_F(Point3Fixture, UpdateX) {
  point.x = new_x;
  ASSERT_EQ(point.x, new_x);
}
TEST_F(Point3Fixture, UpdateY) {
  point.y = new_y;
  ASSERT_EQ(point.y, new_y);
}
TEST_F(Point3Fixture, UpdateZ) {
  point.z = new_z;
  ASSERT_EQ(point.z, new_z);
}

class RwexFixture : public ::testing::Test {
protected:
  onogawa::Point3 ex;
  onogawa::Quaternion Rw;
  onogawa::Point3 ex_prime;

  RwexFixture()
      : ex(onogawa::Point3::ex()), Rw(onogawa::Quaternion::ew()),
        ex_prime(Rw * ex) {}
};

TEST_F(RwexFixture, CheckX) { ASSERT_NEAR(ex_prime.x, ex.x, 1e-14); }
TEST_F(RwexFixture, CheckY) { ASSERT_NEAR(ex_prime.y, ex.y, 1e-14); }
TEST_F(RwexFixture, CheckZ) { ASSERT_NEAR(ex_prime.z, ex.z, 1e-14); }

class RweyFixture : public ::testing::Test {
protected:
  onogawa::Point3 ey;
  onogawa::Quaternion Rw;
  onogawa::Point3 ey_prime;

  RweyFixture()
      : ey(onogawa::Point3::ey()), Rw(onogawa::Quaternion::ew()),
        ey_prime(Rw * ey) {}
};

TEST_F(RweyFixture, CheckX) { ASSERT_NEAR(ey_prime.x, ey.x, 1e-14); }
TEST_F(RweyFixture, CheckY) { ASSERT_NEAR(ey_prime.y, ey.y, 1e-14); }
TEST_F(RweyFixture, CheckZ) { ASSERT_NEAR(ey_prime.z, ey.z, 1e-14); }

class RwezFixture : public ::testing::Test {
protected:
  onogawa::Point3 ez;
  onogawa::Quaternion Rw;
  onogawa::Point3 ez_prime;

  RwezFixture()
      : ez(onogawa::Point3::ez()), Rw(onogawa::Quaternion::ew()),
        ez_prime(Rw * ez) {}
};

TEST_F(RwezFixture, CheckX) { ASSERT_NEAR(ez_prime.x, ez.x, 1e-14); }
TEST_F(RwezFixture, CheckY) { ASSERT_NEAR(ez_prime.y, ez.y, 1e-14); }
TEST_F(RwezFixture, CheckZ) { ASSERT_NEAR(ez_prime.z, ez.z, 1e-14); }

class RxexFixture : public ::testing::Test {
protected:
  onogawa::Point3 ex;
  onogawa::Quaternion Rx;
  onogawa::Point3 ex_prime;

  RxexFixture()
      : ex(onogawa::Point3::ex()), Rx(onogawa::Quaternion::ex()),
        ex_prime(Rx * ex) {}
};

TEST_F(RxexFixture, CheckX) { ASSERT_NEAR(ex_prime.x, ex.x, 1e-14); }
TEST_F(RxexFixture, CheckY) { ASSERT_NEAR(ex_prime.y, ex.y, 1e-14); }
TEST_F(RxexFixture, CheckZ) { ASSERT_NEAR(ex_prime.z, ex.z, 1e-14); }

class RxeyFixture : public ::testing::Test {
protected:
  onogawa::Point3 ey;
  onogawa::Quaternion Rx;
  onogawa::Point3 ey_prime;

  RxeyFixture()
      : ey(onogawa::Point3::ey()), Rx(onogawa::Quaternion::ex()),
        ey_prime(Rx * ey) {}
};

TEST_F(RxeyFixture, CheckX) { ASSERT_NEAR(ey_prime.x, ey.x, 1e-14); }
TEST_F(RxeyFixture, CheckY) { ASSERT_NEAR(ey_prime.y, -ey.y, 1e-14); }
TEST_F(RxeyFixture, CheckZ) { ASSERT_NEAR(ey_prime.z, ey.z, 1e-14); }

class RxezFixture : public ::testing::Test {
protected:
  onogawa::Point3 ez;
  onogawa::Quaternion Rx;
  onogawa::Point3 ez_prime;

  RxezFixture()
      : ez(onogawa::Point3::ez()), Rx(onogawa::Quaternion::ex()),
        ez_prime(Rx * ez) {}
};

TEST_F(RxezFixture, CheckX) { ASSERT_NEAR(ez_prime.x, ez.x, 1e-14); }
TEST_F(RxezFixture, CheckY) { ASSERT_NEAR(ez_prime.y, ez.y, 1e-14); }
TEST_F(RxezFixture, CheckZ) { ASSERT_NEAR(ez_prime.z, -ez.z, 1e-14); }

class RyexFixture : public ::testing::Test {
protected:
  onogawa::Point3 ex;
  onogawa::Quaternion Ry;
  onogawa::Point3 ex_prime;

  RyexFixture()
      : ex(onogawa::Point3::ex()), Ry(onogawa::Quaternion::ey()),
        ex_prime(Ry * ex) {}
};

TEST_F(RyexFixture, CheckX) { ASSERT_NEAR(ex_prime.x, -ex.x, 1e-14); }
TEST_F(RyexFixture, CheckY) { ASSERT_NEAR(ex_prime.y, ex.y, 1e-14); }
TEST_F(RyexFixture, CheckZ) { ASSERT_NEAR(ex_prime.z, ex.z, 1e-14); }

class RyeyFixture : public ::testing::Test {
protected:
  onogawa::Point3 ey;
  onogawa::Quaternion Ry;
  onogawa::Point3 ey_prime;

  RyeyFixture()
      : ey(onogawa::Point3::ey()), Ry(onogawa::Quaternion::ey()),
        ey_prime(Ry * ey) {}
};

TEST_F(RyeyFixture, CheckX) { ASSERT_NEAR(ey_prime.x, ey.x, 1e-14); }
TEST_F(RyeyFixture, CheckY) { ASSERT_NEAR(ey_prime.y, ey.y, 1e-14); }
TEST_F(RyeyFixture, CheckZ) { ASSERT_NEAR(ey_prime.z, ey.z, 1e-14); }

class RyezFixture : public ::testing::Test {
protected:
  onogawa::Point3 ez;
  onogawa::Quaternion Ry;
  onogawa::Point3 ez_prime;

  RyezFixture()
      : ez(onogawa::Point3::ez()), Ry(onogawa::Quaternion::ey()),
        ez_prime(Ry * ez) {}
};

TEST_F(RyezFixture, CheckX) { ASSERT_NEAR(ez_prime.x, ez.x, 1e-14); }
TEST_F(RyezFixture, CheckY) { ASSERT_NEAR(ez_prime.y, ez.y, 1e-14); }
TEST_F(RyezFixture, CheckZ) { ASSERT_NEAR(ez_prime.z, -ez.z, 1e-14); }

class RzexFixture : public ::testing::Test {
protected:
  onogawa::Point3 ex;
  onogawa::Quaternion Rz;
  onogawa::Point3 ex_prime;

  RzexFixture()
      : ex(onogawa::Point3::ex()), Rz(onogawa::Quaternion::ez()),
        ex_prime(Rz * ex) {}
};

TEST_F(RzexFixture, CheckX) { ASSERT_NEAR(ex_prime.x, -ex.x, 1e-14); }
TEST_F(RzexFixture, CheckY) { ASSERT_NEAR(ex_prime.y, ex.y, 1e-14); }
TEST_F(RzexFixture, CheckZ) { ASSERT_NEAR(ex_prime.z, ex.z, 1e-14); }

class RzeyFixture : public ::testing::Test {
protected:
  onogawa::Point3 ey;
  onogawa::Quaternion Rz;
  onogawa::Point3 ey_prime;

  RzeyFixture()
      : ey(onogawa::Point3::ey()), Rz(onogawa::Quaternion::ez()),
        ey_prime(Rz * ey) {}
};

TEST_F(RzeyFixture, CheckX) { ASSERT_NEAR(ey_prime.x, ey.x, 1e-14); }
TEST_F(RzeyFixture, CheckY) { ASSERT_NEAR(ey_prime.y, -ey.y, 1e-14); }
TEST_F(RzeyFixture, CheckZ) { ASSERT_NEAR(ey_prime.z, ey.z, 1e-14); }

class RzezFixture : public ::testing::Test {
protected:
  onogawa::Point3 ez;
  onogawa::Quaternion Rz;
  onogawa::Point3 ez_prime;

  RzezFixture()
      : ez(onogawa::Point3::ez()), Rz(onogawa::Quaternion::ez()),
        ez_prime(Rz * ez) {}
};

TEST_F(RzezFixture, CheckX) { ASSERT_NEAR(ez_prime.x, ez.x, 1e-14); }
TEST_F(RzezFixture, CheckY) { ASSERT_NEAR(ez_prime.y, ez.y, 1e-14); }
TEST_F(RzezFixture, CheckZ) { ASSERT_NEAR(ez_prime.z, ez.z, 1e-14); }

class Pose3Fixture1 : public ::testing::Test {
protected:
  onogawa::Pose3 a;
  onogawa::Pose3 b;
  onogawa::Pose3 c;

  Pose3Fixture1()
      : a(onogawa::Quaternion::ew(), onogawa::Point3::ex()),
        b(onogawa::Quaternion::ew(), onogawa::Point3::ex()), c(a * b) {}
};

TEST_F(Pose3Fixture1, CheckX) { ASSERT_NEAR(c.position.x, 2.0, 1e-14); }
TEST_F(Pose3Fixture1, CheckY) { ASSERT_NEAR(c.position.y, 0.0, 1e-14); }
TEST_F(Pose3Fixture1, CheckZ) { ASSERT_NEAR(c.position.z, 0.0, 1e-14); }
TEST_F(Pose3Fixture1, CheckQw) { ASSERT_NEAR(c.orientation.w, 1.0, 1e-14); }
TEST_F(Pose3Fixture1, CheckQx) { ASSERT_NEAR(c.orientation.x, 0.0, 1e-14); }
TEST_F(Pose3Fixture1, CheckQy) { ASSERT_NEAR(c.orientation.y, 0.0, 1e-14); }
TEST_F(Pose3Fixture1, CheckQz) { ASSERT_NEAR(c.orientation.z, 0.0, 1e-14); }

class Pose3Fixture2 : public ::testing::Test {
protected:
  onogawa::Pose3 a;
  onogawa::Pose3 b;
  onogawa::Pose3 c;

  Pose3Fixture2()
      : a(onogawa::Quaternion::ew(), onogawa::Point3::ez()),
        b(onogawa::Quaternion::ew(), onogawa::Point3::ex()), c(a * b) {}
};
