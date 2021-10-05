cmake_minimum_required(VERSION 3.16)
project(demo)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)
set(CMAKE_BUILD_TYPE Release)

include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(gflags REQUIRED PATHS ${PROJECT_SOURCE_DIR}/third_party/gflags)
find_package(glog REQUIRED PATHS ${PROJECT_SOURCE_DIR}/third_party/glog)
find_package(jsoncpp REQUIRED PATHS ${PROJECT_SOURCE_DIR}/third_party/jsoncpp)

file(GLOB_RECURSE SRCS src/*.cpp)
add_executable(${PROJECT_NAME} main.cpp ${SRCS})

# jsoncpp
target_link_libraries(${PROJECT_NAME} jsoncpp)

# glog
target_link_libraries(${PROJECT_NAME} glog::glog)

# gflags
target_link_libraries(${PROJECT_NAME} gflags)