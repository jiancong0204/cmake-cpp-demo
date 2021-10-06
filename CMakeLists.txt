cmake_minimum_required(VERSION 3.16)
project(demo)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)
set(CMAKE_BUILD_TYPE Release)

# third-party libs
include(${PROJECT_SOURCE_DIR}/third-party/third-party.cmake)
set(THIRD_PARTY_LIBS
  third_party_jsoncpp
  third_party_glog
  third_party_gflags
  third_party_eigen3
)

# source code
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB_RECURSE SRCS src/*.cpp)
add_executable(${PROJECT_NAME} main.cpp ${SRCS})

# link libraries
target_link_libraries(${PROJECT_NAME} ${THIRD_PARTY_LIBS})