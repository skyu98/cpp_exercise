//
// Created by Frank on 2019-12-05.
//

#include <gtest/gtest.h>
#include <iostream>
#include "employee.h"
using namespace std;

TEST(TEST_Employee, getDeptName){
    Worker* worker = NULL;
    worker = new Employee(1, "f", 12);
    worker->showInfo();
    EXPECT_TRUE(worker->getDeptName() == "Employee");
//    Employee em(1, "f", 12);
//    EXPECT_TRUE(em.getDeptName() == "Employee");
    delete worker;
}
