#include "onogawa/onogawa.hpp"
#include <gtest/gtest.h>

class QuaternionFixture : public ::testing::Test {
protected:
  double w;
  double x;
  double y;
  double z;
  onogawa::Quaterniond quat;
  QuaternionFixture()
      : w(1.0), x(0.0), y(0.0), z(0.0), quat(1.0, 0.0, 0.0, 0.0) {}
};

TEST_F(QuaternionFixture, CheckW) { ASSERT_EQ(quat.w, w); }
TEST_F(QuaternionFixture, CheckX) { ASSERT_EQ(quat.x, x); }
TEST_F(QuaternionFixture, CheckY) { ASSERT_EQ(quat.y, y); }
TEST_F(QuaternionFixture, CheckZ) { ASSERT_EQ(quat.z, z); }

class QuaternionMultiplicationEwEw_Ew : public ::testing::Test {
protected:
  onogawa::Quaterniond ew;
  onogawa::Quaterniond c;
  QuaternionMultiplicationEwEw_Ew()
      : ew(onogawa::Quaterniond::ew()), c(ew * ew) {}
};

TEST_F(QuaternionMultiplicationEwEw_Ew, CheckW) {
  ASSERT_NEAR(c.w, ew.w, 1e-14);
}
TEST_F(QuaternionMultiplicationEwEw_Ew, CheckX) {
  ASSERT_NEAR(c.x, ew.x, 1e-14);
}
TEST_F(QuaternionMultiplicationEwEw_Ew, CheckY) {
  ASSERT_NEAR(c.y, ew.y, 1e-14);
}
TEST_F(QuaternionMultiplicationEwEw_Ew, CheckZ) {
  ASSERT_NEAR(c.z, ew.z, 1e-14);
}

class QuaternionMultiplicationEwEx_Ex : public ::testing::Test {
protected:
  onogawa::Quaterniond ew;
  onogawa::Quaterniond ex;
  onogawa::Quaterniond c;
  QuaternionMultiplicationEwEx_Ex()
      : ew(onogawa::Quaterniond::ew()), ex(onogawa::Quaterniond::ex()),
        c(ew * ex) {}
};

TEST_F(QuaternionMultiplicationEwEx_Ex, CheckW) {
  ASSERT_NEAR(c.w, ex.w, 1e-14);
}
TEST_F(QuaternionMultiplicationEwEx_Ex, CheckX) {
  ASSERT_NEAR(c.x, ex.x, 1e-14);
}
TEST_F(QuaternionMultiplicationEwEx_Ex, CheckY) {
  ASSERT_NEAR(c.y, ex.y, 1e-14);
}
TEST_F(QuaternionMultiplicationEwEx_Ex, CheckZ) {
  ASSERT_NEAR(c.z, ex.z, 1e-14);
}

class QuaternionMultiplicationEwEy_Ey : public ::testing::Test {
protected:
  onogawa::Quaterniond ew;
  onogawa::Quaterniond ey;
  onogawa::Quaterniond c;
  QuaternionMultiplicationEwEy_Ey()
      : ew(onogawa::Quaterniond::ew()), ey(onogawa::Quaterniond::ey()),
        c(ew * ey) {}
};

TEST_F(QuaternionMultiplicationEwEy_Ey, CheckW) {
  ASSERT_NEAR(c.w, ey.w, 1e-14);
}
TEST_F(QuaternionMultiplicationEwEy_Ey, CheckX) {
  ASSERT_NEAR(c.x, ey.x, 1e-14);
}
TEST_F(QuaternionMultiplicationEwEy_Ey, CheckY) {
  ASSERT_NEAR(c.y, ey.y, 1e-14);
}
TEST_F(QuaternionMultiplicationEwEy_Ey, CheckZ) {
  ASSERT_NEAR(c.z, ey.z, 1e-14);
}

class QuaternionMultiplicationEwEz_Ez : public ::testing::Test {
protected:
  onogawa::Quaterniond ew;
  onogawa::Quaterniond ez;
  onogawa::Quaterniond c;
  QuaternionMultiplicationEwEz_Ez()
      : ew(onogawa::Quaterniond::ew()), ez(onogawa::Quaterniond::ez()),
        c(ew * ez) {}
};

TEST_F(QuaternionMultiplicationEwEz_Ez, CheckW) {
  ASSERT_NEAR(c.w, ez.w, 1e-14);
}
TEST_F(QuaternionMultiplicationEwEz_Ez, CheckX) {
  ASSERT_NEAR(c.x, ez.x, 1e-14);
}
TEST_F(QuaternionMultiplicationEwEz_Ez, CheckY) {
  ASSERT_NEAR(c.y, ez.y, 1e-14);
}
TEST_F(QuaternionMultiplicationEwEz_Ez, CheckZ) {
  ASSERT_NEAR(c.z, ez.z, 1e-14);
}

class QuaternionMultiplicationExEw_Ex : public ::testing::Test {
protected:
  onogawa::Quaterniond ex;
  onogawa::Quaterniond ew;
  onogawa::Quaterniond c;
  QuaternionMultiplicationExEw_Ex()
      : ex(onogawa::Quaterniond::ex()), ew(onogawa::Quaterniond::ew()),
        c(ex * ew) {}
};

TEST_F(QuaternionMultiplicationExEw_Ex, CheckW) {
  ASSERT_NEAR(c.w, ex.w, 1e-14);
}
TEST_F(QuaternionMultiplicationExEw_Ex, CheckX) {
  ASSERT_NEAR(c.x, ex.x, 1e-14);
}
TEST_F(QuaternionMultiplicationExEw_Ex, CheckY) {
  ASSERT_NEAR(c.y, ex.y, 1e-14);
}
TEST_F(QuaternionMultiplicationExEw_Ex, CheckZ) {
  ASSERT_NEAR(c.z, ex.z, 1e-14);
}

class QuaternionMultiplicationExEx_NegEw : public ::testing::Test {
protected:
  onogawa::Quaterniond ew;
  onogawa::Quaterniond ex;
  onogawa::Quaterniond c;
  QuaternionMultiplicationExEx_NegEw()
      : ew(onogawa::Quaterniond::ew()), ex(onogawa::Quaterniond::ex()),
        c(ex * ex) {}
};

TEST_F(QuaternionMultiplicationExEx_NegEw, CheckW) {
  ASSERT_NEAR(c.w, -ew.w, 1e-14);
}
TEST_F(QuaternionMultiplicationExEx_NegEw, CheckX) {
  ASSERT_NEAR(c.x, -ew.x, 1e-14);
}
TEST_F(QuaternionMultiplicationExEx_NegEw, CheckY) {
  ASSERT_NEAR(c.y, -ew.y, 1e-14);
}
TEST_F(QuaternionMultiplicationExEx_NegEw, CheckZ) {
  ASSERT_NEAR(c.z, -ew.z, 1e-14);
}

class QuaternionMultiplicationExEy_Ez : public ::testing::Test {
protected:
  onogawa::Quaterniond ex;
  onogawa::Quaterniond ey;
  onogawa::Quaterniond ez;
  onogawa::Quaterniond c;
  QuaternionMultiplicationExEy_Ez()
      : ex(onogawa::Quaterniond::ex()), ey(onogawa::Quaterniond::ey()),
        ez(onogawa::Quaterniond::ez()), c(ex * ey) {}
};

TEST_F(QuaternionMultiplicationExEy_Ez, CheckW) {
  ASSERT_NEAR(c.w, ez.w, 1e-14);
}
TEST_F(QuaternionMultiplicationExEy_Ez, CheckX) {
  ASSERT_NEAR(c.x, ez.x, 1e-14);
}
TEST_F(QuaternionMultiplicationExEy_Ez, CheckY) {
  ASSERT_NEAR(c.y, ez.y, 1e-14);
}
TEST_F(QuaternionMultiplicationExEy_Ez, CheckZ) {
  ASSERT_NEAR(c.z, ez.z, 1e-14);
}

class QuaternionMultiplicationExEz_NegEy : public ::testing::Test {
protected:
  onogawa::Quaterniond ex;
  onogawa::Quaterniond ey;
  onogawa::Quaterniond ez;
  onogawa::Quaterniond c;
  QuaternionMultiplicationExEz_NegEy()
      : ex(onogawa::Quaterniond::ex()), ey(onogawa::Quaterniond::ey()),
        ez(onogawa::Quaterniond::ez()), c(ex * ez) {}
};

TEST_F(QuaternionMultiplicationExEz_NegEy, CheckW) {
  ASSERT_NEAR(c.w, -ey.w, 1e-14);
}
TEST_F(QuaternionMultiplicationExEz_NegEy, CheckX) {
  ASSERT_NEAR(c.x, -ey.x, 1e-14);
}
TEST_F(QuaternionMultiplicationExEz_NegEy, CheckY) {
  ASSERT_NEAR(c.y, -ey.y, 1e-14);
}
TEST_F(QuaternionMultiplicationExEz_NegEy, CheckZ) {
  ASSERT_NEAR(c.z, -ey.z, 1e-14);
}

class QuaternionMultiplicationEyEw_Ey : public ::testing::Test {
protected:
  onogawa::Quaterniond ew;
  onogawa::Quaterniond ey;
  onogawa::Quaterniond c;
  QuaternionMultiplicationEyEw_Ey()
      : ew(onogawa::Quaterniond::ew()), ey(onogawa::Quaterniond::ey()),
        c(ey * ew) {}
};

TEST_F(QuaternionMultiplicationEyEw_Ey, CheckW) {
  ASSERT_NEAR(c.w, ey.w, 1e-14);
}
TEST_F(QuaternionMultiplicationEyEw_Ey, CheckX) {
  ASSERT_NEAR(c.x, ey.x, 1e-14);
}
TEST_F(QuaternionMultiplicationEyEw_Ey, CheckY) {
  ASSERT_NEAR(c.y, ey.y, 1e-14);
}
TEST_F(QuaternionMultiplicationEyEw_Ey, CheckZ) {
  ASSERT_NEAR(c.z, ey.z, 1e-14);
}

class QuaternionMultiplicationEyEx_NegEz : public ::testing::Test {
protected:
  onogawa::Quaterniond ex;
  onogawa::Quaterniond ey;
  onogawa::Quaterniond ez;
  onogawa::Quaterniond c;
  QuaternionMultiplicationEyEx_NegEz()
      : ex(onogawa::Quaterniond::ex()), ey(onogawa::Quaterniond::ey()),
        ez(onogawa::Quaterniond::ez()), c(ey * ex) {}
};

TEST_F(QuaternionMultiplicationEyEx_NegEz, CheckW) {
  ASSERT_NEAR(c.w, -ez.w, 1e-14);
}
TEST_F(QuaternionMultiplicationEyEx_NegEz, CheckX) {
  ASSERT_NEAR(c.x, -ez.x, 1e-14);
}
TEST_F(QuaternionMultiplicationEyEx_NegEz, CheckY) {
  ASSERT_NEAR(c.y, -ez.y, 1e-14);
}
TEST_F(QuaternionMultiplicationEyEx_NegEz, CheckZ) {
  ASSERT_NEAR(c.z, -ez.z, 1e-14);
}

class QuaternionMultiplicationEyEy_NegEw : public ::testing::Test {
protected:
  onogawa::Quaterniond ew;
  onogawa::Quaterniond ey;
  onogawa::Quaterniond c;
  QuaternionMultiplicationEyEy_NegEw()
      : ew(onogawa::Quaterniond::ew()), ey(onogawa::Quaterniond::ey()),
        c(ey * ey) {}
};

TEST_F(QuaternionMultiplicationEyEy_NegEw, CheckW) {
  ASSERT_NEAR(c.w, -ew.w, 1e-14);
}
TEST_F(QuaternionMultiplicationEyEy_NegEw, CheckX) {
  ASSERT_NEAR(c.x, -ew.x, 1e-14);
}
TEST_F(QuaternionMultiplicationEyEy_NegEw, CheckY) {
  ASSERT_NEAR(c.y, -ew.y, 1e-14);
}
TEST_F(QuaternionMultiplicationEyEy_NegEw, CheckZ) {
  ASSERT_NEAR(c.z, -ew.z, 1e-14);
}

class QuaternionMultiplicationEyEz_Ex : public ::testing::Test {
protected:
  onogawa::Quaterniond ex;
  onogawa::Quaterniond ey;
  onogawa::Quaterniond ez;
  onogawa::Quaterniond c;
  QuaternionMultiplicationEyEz_Ex()
      : ex(onogawa::Quaterniond::ex()), ey(onogawa::Quaterniond::ey()),
        ez(onogawa::Quaterniond::ez()), c(ey * ez) {}
};

TEST_F(QuaternionMultiplicationEyEz_Ex, CheckW) {
  ASSERT_NEAR(c.w, ex.w, 1e-14);
}
TEST_F(QuaternionMultiplicationEyEz_Ex, CheckX) {
  ASSERT_NEAR(c.x, ex.x, 1e-14);
}
TEST_F(QuaternionMultiplicationEyEz_Ex, CheckY) {
  ASSERT_NEAR(c.y, ex.y, 1e-14);
}
TEST_F(QuaternionMultiplicationEyEz_Ex, CheckZ) {
  ASSERT_NEAR(c.z, ex.z, 1e-14);
}

class QuaternionMultiplicationEzEw_Ez : public ::testing::Test {
protected:
  onogawa::Quaterniond ew;
  onogawa::Quaterniond ez;
  onogawa::Quaterniond c;
  QuaternionMultiplicationEzEw_Ez()
      : ew(onogawa::Quaterniond::ew()), ez(onogawa::Quaterniond::ez()),
        c(ew * ez) {}
};

TEST_F(QuaternionMultiplicationEzEw_Ez, CheckW) {
  ASSERT_NEAR(c.w, ez.w, 1e-14);
}
TEST_F(QuaternionMultiplicationEzEw_Ez, CheckX) {
  ASSERT_NEAR(c.x, ez.x, 1e-14);
}
TEST_F(QuaternionMultiplicationEzEw_Ez, CheckY) {
  ASSERT_NEAR(c.y, ez.y, 1e-14);
}
TEST_F(QuaternionMultiplicationEzEw_Ez, CheckZ) {
  ASSERT_NEAR(c.z, ez.z, 1e-14);
}

class QuaternionMultiplicationEzEx_Ey : public ::testing::Test {
protected:
  onogawa::Quaterniond ex;
  onogawa::Quaterniond ey;
  onogawa::Quaterniond ez;
  onogawa::Quaterniond c;
  QuaternionMultiplicationEzEx_Ey()
      : ex(onogawa::Quaterniond::ex()), ey(onogawa::Quaterniond::ey()),
        ez(onogawa::Quaterniond::ez()), c(ez * ex) {}
};

TEST_F(QuaternionMultiplicationEzEx_Ey, CheckW) {
  ASSERT_NEAR(c.w, ey.w, 1e-14);
}
TEST_F(QuaternionMultiplicationEzEx_Ey, CheckX) {
  ASSERT_NEAR(c.x, ey.x, 1e-14);
}
TEST_F(QuaternionMultiplicationEzEx_Ey, CheckY) {
  ASSERT_NEAR(c.y, ey.y, 1e-14);
}
TEST_F(QuaternionMultiplicationEzEx_Ey, CheckZ) {
  ASSERT_NEAR(c.z, ey.z, 1e-14);
}

class QuaternionMultiplicationEzEy_NegEx : public ::testing::Test {
protected:
  onogawa::Quaterniond ex;
  onogawa::Quaterniond ey;
  onogawa::Quaterniond ez;
  onogawa::Quaterniond c;
  QuaternionMultiplicationEzEy_NegEx()
      : ex(onogawa::Quaterniond::ex()), ey(onogawa::Quaterniond::ey()),
        ez(onogawa::Quaterniond::ez()), c(ez * ey) {}
};

TEST_F(QuaternionMultiplicationEzEy_NegEx, CheckW) {
  ASSERT_NEAR(c.w, -ex.w, 1e-14);
}
TEST_F(QuaternionMultiplicationEzEy_NegEx, CheckX) {
  ASSERT_NEAR(c.x, -ex.x, 1e-14);
}
TEST_F(QuaternionMultiplicationEzEy_NegEx, CheckY) {
  ASSERT_NEAR(c.y, -ex.y, 1e-14);
}
TEST_F(QuaternionMultiplicationEzEy_NegEx, CheckZ) {
  ASSERT_NEAR(c.z, -ex.z, 1e-14);
}

class QuaternionMultiplicationEzEz_NegEw : public ::testing::Test {
protected:
  onogawa::Quaterniond ew;
  onogawa::Quaterniond ez;
  onogawa::Quaterniond c;
  QuaternionMultiplicationEzEz_NegEw()
      : ew(onogawa::Quaterniond::ew()), ez(onogawa::Quaterniond::ez()),
        c(ez * ez) {}
};

TEST_F(QuaternionMultiplicationEzEz_NegEw, CheckW) {
  ASSERT_NEAR(c.w, -ew.w, 1e-14);
}
TEST_F(QuaternionMultiplicationEzEz_NegEw, CheckX) {
  ASSERT_NEAR(c.x, -ew.x, 1e-14);
}
TEST_F(QuaternionMultiplicationEzEz_NegEw, CheckY) {
  ASSERT_NEAR(c.y, -ew.y, 1e-14);
}
TEST_F(QuaternionMultiplicationEzEz_NegEw, CheckZ) {
  ASSERT_NEAR(c.z, -ew.z, 1e-14);
}