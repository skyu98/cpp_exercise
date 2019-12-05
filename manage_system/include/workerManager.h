//
// Created by Frank on 2019-12-03.
//

#ifndef MANAGE_SYSTEM_WORKERMANAGER_H
#define MANAGE_SYSTEM_WORKERMANAGER_H

#include <iostream>
#include "worker.h"

using namespace std;

class WorkerManager{
public:
    WorkerManager();
    ~WorkerManager();

    void Show_Menu();

    // 0.exit
    void ExitSystem();
    // 1.add
    void Add_Emp();


    //记录职工人数
    int m_EmpNum;

    //职工数组指针
    Worker** m_EmpArray;

};

#endif //MANAGE_SYSTEM_WORKERMANAGER_H
