#include "onogawa/onogawa.hpp"
#include <gtest/gtest.h>

class Point2Fixture : public ::testing::Test {
protected:
  double x;
  double y;
  double new_x;
  double new_y;
  onogawa::Point2 point;
  Point2Fixture() : x(0.0), y(1.0), new_x(2.0), new_y(3.0), point(x, y) {}
};

TEST_F(Point2Fixture, CheckX) { ASSERT_EQ(point.x(), x); }
TEST_F(Point2Fixture, CheckY) { ASSERT_EQ(point.y(), y); }
TEST_F(Point2Fixture, UpdateX) {
  point.x() = new_x;
  ASSERT_EQ(point.x(), new_x);
}
TEST_F(Point2Fixture, UpdateY) {
  point.y() = new_y;
  ASSERT_EQ(point.y(), new_y);
}

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

TEST_F(Point3Fixture, CheckX) { ASSERT_EQ(point.x(), x); }
TEST_F(Point3Fixture, CheckY) { ASSERT_EQ(point.y(), y); }
TEST_F(Point3Fixture, CheckZ) { ASSERT_EQ(point.z(), z); }
TEST_F(Point3Fixture, UpdateX) {
  point.x() = new_x;
  ASSERT_EQ(point.x(), new_x);
}
TEST_F(Point3Fixture, UpdateY) {
  point.y() = new_y;
  ASSERT_EQ(point.y(), new_y);
}
TEST_F(Point3Fixture, UpdateZ) {
  point.z() = new_z;
  ASSERT_EQ(point.z(), new_z);
}

class RwexFixture : public ::testing::Test {
protected:
  onogawa::Point3 ex;
  onogawa::Quaternion Rw;
  onogawa::Point3 ex_prime;

  RwexFixture()
      : ex(1.0, 0.0, 0.0), Rw(1.0, 0.0, 0.0, 0.0), ex_prime(Rw * ex) {}
};

TEST_F(RwexFixture, CheckX) { ASSERT_NEAR(ex_prime.x(), ex.x(), 1e-14); }
TEST_F(RwexFixture, CheckY) { ASSERT_NEAR(ex_prime.y(), ex.y(), 1e-14); }
TEST_F(RwexFixture, CheckZ) { ASSERT_NEAR(ex_prime.z(), ex.z(), 1e-14); }

class RweyFixture : public ::testing::Test {
protected:
  onogawa::Point3 ey;
  onogawa::Quaternion Rw;
  onogawa::Point3 ey_prime;

  RweyFixture()
      : ey(0.0, 1.0, 0.0), Rw(1.0, 0.0, 0.0, 0.0), ey_prime(Rw * ey) {}
};

TEST_F(RweyFixture, CheckX) { ASSERT_NEAR(ey_prime.x(), ey.x(), 1e-14); }
TEST_F(RweyFixture, CheckY) { ASSERT_NEAR(ey_prime.y(), ey.y(), 1e-14); }
TEST_F(RweyFixture, CheckZ) { ASSERT_NEAR(ey_prime.z(), ey.z(), 1e-14); }

class RwezFixture : public ::testing::Test {
protected:
  onogawa::Point3 ez;
  onogawa::Quaternion Rw;
  onogawa::Point3 ez_prime;

  RwezFixture()
      : ez(0.0, 0.0, 1.0), Rw(1.0, 0.0, 0.0, 0.0), ez_prime(Rw * ez) {}
};

TEST_F(RwezFixture, CheckX) { ASSERT_NEAR(ez_prime.x(), ez.x(), 1e-14); }
TEST_F(RwezFixture, CheckY) { ASSERT_NEAR(ez_prime.y(), ez.y(), 1e-14); }
TEST_F(RwezFixture, CheckZ) { ASSERT_NEAR(ez_prime.z(), ez.z(), 1e-14); }

class RxexFixture : public ::testing::Test {
protected:
  onogawa::Point3 ex;
  onogawa::Quaternion Rx;
  onogawa::Point3 ex_prime;

  RxexFixture()
      : ex(1.0, 0.0, 0.0), Rx(0.0, 1.0, 0.0, 0.0), ex_prime(Rx * ex) {}
};

TEST_F(RxexFixture, CheckX) { ASSERT_NEAR(ex_prime.x(), ex.x(), 1e-14); }
TEST_F(RxexFixture, CheckY) { ASSERT_NEAR(ex_prime.y(), ex.y(), 1e-14); }
TEST_F(RxexFixture, CheckZ) { ASSERT_NEAR(ex_prime.z(), ex.z(), 1e-14); }

class RxeyFixture : public ::testing::Test {
protected:
  onogawa::Point3 ey;
  onogawa::Quaternion Rx;
  onogawa::Point3 ey_prime;

  RxeyFixture()
      : ey(0.0, 1.0, 0.0), Rx(0.0, 1.0, 0.0, 0.0), ey_prime(Rx * ey) {}
};

TEST_F(RxeyFixture, CheckX) { ASSERT_NEAR(ey_prime.x(), ey.x(), 1e-14); }
TEST_F(RxeyFixture, CheckY) { ASSERT_NEAR(ey_prime.y(), -ey.y(), 1e-14); }
TEST_F(RxeyFixture, CheckZ) { ASSERT_NEAR(ey_prime.z(), ey.z(), 1e-14); }

class RxezFixture : public ::testing::Test {
protected:
  onogawa::Point3 ez;
  onogawa::Quaternion Rx;
  onogawa::Point3 ez_prime;

  RxezFixture()
      : ez(0.0, 0.0, 1.0), Rx(0.0, 1.0, 0.0, 0.0), ez_prime(Rx * ez) {}
};

TEST_F(RxezFixture, CheckX) { ASSERT_NEAR(ez_prime.x(), ez.x(), 1e-14); }
TEST_F(RxezFixture, CheckY) { ASSERT_NEAR(ez_prime.y(), ez.y(), 1e-14); }
TEST_F(RxezFixture, CheckZ) { ASSERT_NEAR(ez_prime.z(), -ez.z(), 1e-14); }

class RyexFixture : public ::testing::Test {
protected:
  onogawa::Point3 ex;
  onogawa::Quaternion Ry;
  onogawa::Point3 ex_prime;

  RyexFixture()
      : ex(1.0, 0.0, 0.0), Ry(0.0, 0.0, 1.0, 0.0), ex_prime(Ry * ex) {}
};

TEST_F(RyexFixture, CheckX) { ASSERT_NEAR(ex_prime.x(), -ex.x(), 1e-14); }
TEST_F(RyexFixture, CheckY) { ASSERT_NEAR(ex_prime.y(), ex.y(), 1e-14); }
TEST_F(RyexFixture, CheckZ) { ASSERT_NEAR(ex_prime.z(), ex.z(), 1e-14); }

class RyeyFixture : public ::testing::Test {
protected:
  onogawa::Point3 ey;
  onogawa::Quaternion Ry;
  onogawa::Point3 ey_prime;

  RyeyFixture()
      : ey(0.0, 1.0, 0.0), Ry(0.0, 0.0, 1.0, 0.0), ey_prime(Ry * ey) {}
};

TEST_F(RyeyFixture, CheckX) { ASSERT_NEAR(ey_prime.x(), ey.x(), 1e-14); }
TEST_F(RyeyFixture, CheckY) { ASSERT_NEAR(ey_prime.y(), ey.y(), 1e-14); }
TEST_F(RyeyFixture, CheckZ) { ASSERT_NEAR(ey_prime.z(), ey.z(), 1e-14); }

class RyezFixture : public ::testing::Test {
protected:
  onogawa::Point3 ez;
  onogawa::Quaternion Ry;
  onogawa::Point3 ez_prime;

  RyezFixture()
      : ez(0.0, 0.0, 1.0), Ry(0.0, 0.0, 1.0, 0.0), ez_prime(Ry * ez) {}
};

TEST_F(RyezFixture, CheckX) { ASSERT_NEAR(ez_prime.x(), ez.x(), 1e-14); }
TEST_F(RyezFixture, CheckY) { ASSERT_NEAR(ez_prime.y(), ez.y(), 1e-14); }
TEST_F(RyezFixture, CheckZ) { ASSERT_NEAR(ez_prime.z(), -ez.z(), 1e-14); }

class RzexFixture : public ::testing::Test {
protected:
  onogawa::Point3 ex;
  onogawa::Quaternion Rz;
  onogawa::Point3 ex_prime;

  RzexFixture()
      : ex(1.0, 0.0, 0.0), Rz(0.0, 0.0, 0.0, 1.0), ex_prime(Rz * ex) {}
};

TEST_F(RzexFixture, CheckX) { ASSERT_NEAR(ex_prime.x(), -ex.x(), 1e-14); }
TEST_F(RzexFixture, CheckY) { ASSERT_NEAR(ex_prime.y(), ex.y(), 1e-14); }
TEST_F(RzexFixture, CheckZ) { ASSERT_NEAR(ex_prime.z(), ex.z(), 1e-14); }

class RzeyFixture : public ::testing::Test {
protected:
  onogawa::Point3 ey;
  onogawa::Quaternion Rz;
  onogawa::Point3 ey_prime;

  RzeyFixture()
      : ey(0.0, 1.0, 0.0), Rz(0.0, 0.0, 0.0, 1.0), ey_prime(Rz * ey) {}
};

TEST_F(RzeyFixture, CheckX) { ASSERT_NEAR(ey_prime.x(), ey.x(), 1e-14); }
TEST_F(RzeyFixture, CheckY) { ASSERT_NEAR(ey_prime.y(), -ey.y(), 1e-14); }
TEST_F(RzeyFixture, CheckZ) { ASSERT_NEAR(ey_prime.z(), ey.z(), 1e-14); }

class RzezFixture : public ::testing::Test {
protected:
  onogawa::Point3 ez;
  onogawa::Quaternion Rz;
  onogawa::Point3 ez_prime;

  RzezFixture()
      : ez(0.0, 0.0, 1.0), Rz(0.0, 0.0, 0.0, 1.0), ez_prime(Rz * ez) {}
};

TEST_F(RzezFixture, CheckX) { ASSERT_NEAR(ez_prime.x(), ez.x(), 1e-14); }
TEST_F(RzezFixture, CheckY) { ASSERT_NEAR(ez_prime.y(), ez.y(), 1e-14); }
TEST_F(RzezFixture, CheckZ) { ASSERT_NEAR(ez_prime.z(), ez.z(), 1e-14); }
