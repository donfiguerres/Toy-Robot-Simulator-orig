include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(../src)

add_executable(
  RobotTest
  RobotTest.cpp
)

target_link_libraries(
  RobotTest
  robot_core
  gtest_main
)

add_executable(
  ParserTest
  ParserTest.cpp
)

target_link_libraries(
  ParserTest
  robot_core
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(RobotTest)
gtest_discover_tests(ParserTest)