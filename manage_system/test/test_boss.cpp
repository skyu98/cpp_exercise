//
// Created by Frank on 2019-12-05.
//

#include <gtest/gtest.h>
#include <iostream>
#include "boss.h"
using namespace std;

TEST(TEST_Boss, getDeptName){
    Worker* worker = NULL;
    worker = new Boss(3, "b", 22);
    worker->showInfo();
    EXPECT_TRUE(worker->getDeptName() == "Boss");
    delete worker;
}
