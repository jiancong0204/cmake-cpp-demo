cmake_minimum_required(VERSION 3.16)
project(demo)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)
set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS  ON)

set(CMAKE_CXX_FLAGS "-fopenmp")

# third-party libs
include(${PROJECT_SOURCE_DIR}/third-party/third-party.cmake)
include_directories(
  ${THIRD_PARTY_INCLUDE}
)

# pcl
find_package(PCL QUIET REQUIRED)
message("Found PCL version: ${PCL_VERSION}")
include_directories(
  ${PCL_LIBRARY_DIRS}
)

# source code
include_directories(
  ${PROJECT_SOURCE_DIR}/include
)

file(GLOB_RECURSE SRCS src/*.cpp)
add_executable(${PROJECT_NAME} main.cpp ${SRCS})

# link libraries
target_link_libraries(${PROJECT_NAME} ${THIRD_PARTY_LIBS} ${PCL_LIBRARIES})