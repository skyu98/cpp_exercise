//
// Created by Frank on 2019-12-03.
//

#ifndef MANAGE_SYSTEM_MANAGER_H
#define MANAGE_SYSTEM_MANAGER_H

#include <iostream>
#include "worker.h"
using namespace std;

class Manager : public Worker{
public:
    Manager(int id, string name, int dId);
    ~Manager();
    virtual void showInfo();
    virtual string getDeptName();
};

#endif //MANAGE_SYSTEM_MANAGER_H
