//
// Created by Frank on 2019-12-03.
//

#ifndef MANAGE_SYSTEM_BOSS_H
#define MANAGE_SYSTEM_BOSS_H
#include <iostream>
#include "worker.h"
using namespace std;

class Boss : public Worker{
public:
    Boss(int id, string name, int dId);
    ~Boss();
    virtual void showInfo();
    virtual string getDeptName();
};


#endif //MANAGE_SYSTEM_BOSS_H
