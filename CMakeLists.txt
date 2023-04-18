cmake_minimum_required(VERSION 3.16)
project(Onogawa)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
  Sabai
  GIT_REPOSITORY git@github.com:taylorpool/sabai.git
  GIT_TAG main
)
FetchContent_MakeAvailable(Sabai)

add_library(onogawa INTERFACE)
target_include_directories(onogawa
  INTERFACE
  include
)
target_link_libraries(onogawa
  INTERFACE
  sabai
)

option(BUILD_Onogawa_TESTS "Build Onogawa Tests" OFF)

if(BUILD_Onogawa_TESTS)
  include(FetchContent)
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.13.0
  )
  FetchContent_MakeAvailable(googletest)

  enable_testing()

  add_executable(test_onogawa
    test/test_onogawa.cpp
    test/test_quaternion.cpp
  )
  target_link_libraries(test_onogawa
    onogawa
    GTest::gtest_main
  )

  include(GoogleTest)
  gtest_discover_tests(test_onogawa)

endif()