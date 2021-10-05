cmake_minimum_required(VERSION 3.16)
project(demo)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)
set(CMAKE_BUILD_TYPE Release)

include_directories(${PROJECT_SOURCE_DIR}/include)
include(${PROJECT_SOURCE_DIR}/third_party/third_party.cmake)

file(GLOB_RECURSE SRCS src/*.cpp)
add_executable(${PROJECT_NAME} main.cpp ${SRCS})

# jsoncpp
target_link_libraries(${PROJECT_NAME} third_party_jsoncpp)

# glog
target_link_libraries(${PROJECT_NAME} third_party_glog)

# gflags
target_link_libraries(${PROJECT_NAME} third_party_gflags)