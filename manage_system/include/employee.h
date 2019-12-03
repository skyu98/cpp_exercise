//
// Created by Frank on 2019-12-03.
//
// 普通员工

#ifndef MANAGE_SYSTEM_EMPLOYEE_H
#define MANAGE_SYSTEM_EMPLOYEE_H

#include <iostream>
using namespace std;
#include "worker.h"

class Employee : public Worker{
public:
    Employee(int id, string name, int dId);
    virtual ~Employee();
    //virtual可去可不去，但是=0要去掉
    virtual void showInfo();
    virtual string getDeptName();
};


#endif //MANAGE_SYSTEM_EMPLOYEE_H
