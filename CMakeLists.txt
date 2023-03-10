cmake_minimum_required(VERSION 3.16)
project(Onogawa)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

add_library(onogawa
  src/onogawa.cpp
)
target_include_directories(onogawa
  PUBLIC
  include
)
target_link_libraries(onogawa
  PUBLIC
)

option(BUILD_Onogawa_TESTS "Build Onogawa Tests" OFF)

if(BUILD_Onogawa_TESTS)
  find_package(GTest REQUIRED)

  add_executable(test_onogawa
    test/test_onogawa.cpp
    test/test_quaternion.cpp
  )
  target_link_libraries(test_onogawa
    onogawa
    GTest::GTest
    GTest::Main
  )
  include(GoogleTest)
  gtest_discover_tests(test_onogawa)

endif()