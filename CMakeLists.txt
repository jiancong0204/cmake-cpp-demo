cmake_minimum_required(VERSION 3.16)
project(demo)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE SRCS src/*.cpp)
add_executable(${PROJECT_NAME} main.cpp ${SRCS})

# jsoncpp
add_subdirectory(${PROJECT_SOURCE_DIR}/third_party/jsoncpp)
target_link_libraries(${PROJECT_NAME} jsoncpp)

# glog
target_link_libraries(${PROJECT_NAME} glog)

# gflags
target_link_libraries(${PROJECT_NAME} gflags)