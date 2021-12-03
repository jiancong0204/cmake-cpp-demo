cmake_minimum_required(VERSION 3.16)
project(demo)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS  ON)

# third-party libs
include(${PROJECT_SOURCE_DIR}/third-party/third-party.cmake)
set(THIRD_PARTY_LIBS
  third_party_jsoncpp
  third_party_glog
  third_party_gflags
  third_party_eigen3
)

# pcl
find_package(PCL REQUIRED)
message("PCL version: ${PCL_VERSION_NUMBER}")

# source code
include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${Boost_INCLUDE_DIRS}
)

file(GLOB_RECURSE SRCS src/*.cpp)
add_executable(${PROJECT_NAME} main.cpp ${SRCS})

# link libraries
target_link_libraries(${PROJECT_NAME} ${THIRD_PARTY_LIBS} ${Boost_LIBRARIES})