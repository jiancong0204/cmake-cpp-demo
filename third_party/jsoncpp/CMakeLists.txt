cmake_minimum_required(VERSION 3.16)
project(jsoncpp)

file(GLOB JSONCPP_SRCS ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_library(${PROJECT_NAME} ${JSONCPP_SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)