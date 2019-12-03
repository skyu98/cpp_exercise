//
// Created by Frank on 2019-12-03.
//

#ifndef MANAGE_SYSTEM_WORKER_H
#define MANAGE_SYSTEM_WORKER_H

#include <iostream>
#include <string>
using namespace std;

class Worker{
public:
    virtual void showInfo() = 0;
    virtual string getDeptName() = 0;
    virtual ~Worker() {};  //注意多态的析构函数如何写
    int m_Id;
    string m_Name;
    int m_DeptId;
};





#endif //MANAGE_SYSTEM_WORKER_H
