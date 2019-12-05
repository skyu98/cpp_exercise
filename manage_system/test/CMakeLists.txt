# 查找 GTest 库
find_package(GTest REQUIRED)
# GTest 的头文件
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB FILE_TEST ./*.cpp)
file(GLOB FILE_SRC ../src/*.cpp)
# 这里不想存main进去
list(FILTER FILE_SRC EXCLUDE REGEX ".*main.cpp$")

#message("File test" ${FILE_TEST})
#message("File src" ${FILE_SRC})

add_executable(test_my_class
#        ${TEST_FILE} ${FILE_SRC}
#        ${TEST_FILE} ../src/employee.cpp
        test_employee.cpp ../src/employee.cpp
        test_manager.cpp ../src/manager.cpp
        )

# 链接测试库
target_link_libraries(test_my_class
        ${GTEST_BOTH_LIBRARIES}
        pthread)

# 添加到测试
gtest_discover_tests(test_my_class)