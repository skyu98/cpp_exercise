//
// Created by Frank on 2019-12-05.
//

#include <gtest/gtest.h>
#include <iostream>
#include "manager.h"
using namespace std;

TEST(TEST_Manager, getDeptName){
    Worker* worker = NULL;
    worker = new Manager(2, "a", 2);
    worker->showInfo();
    EXPECT_TRUE(worker->getDeptName() == "Manager");
    delete worker;
}
