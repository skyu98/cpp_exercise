cmake_minimum_required(VERSION 3.13)
project(manage_system)

set(CMAKE_CXX_STANDARD 14)

INCLUDE_DIRECTORIES(include)


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/obj)

ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(test)

# 开启测试
enable_testing()

