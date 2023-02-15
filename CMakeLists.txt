cmake_minimum_required(VERSION 3.16)
project(Onogawa)

option(BUILD_TESTS "Build Onogawa Tests" ON)

if(BUILD_TESTS)
  find_package(GTest REQUIRED)

  add_executable(test_onogawa
    test/test_onogawa.cpp
  )
  target_link_libraries(test_onogawa
    GTest::GTest
    GTest::Main
  )
  include(GoogleTest)
  gtest_discover_tests(test_onogawa)

endif()