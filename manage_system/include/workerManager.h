//
// Created by Frank on 2019-12-03.
//

#ifndef MANAGE_SYSTEM_WORKERMANAGER_H
#define MANAGE_SYSTEM_WORKERMANAGER_H

#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
using namespace std;

#define FILENAME "empFile.txt"

class WorkerManager{
public:
    WorkerManager();
    virtual ~WorkerManager();

    void Show_Menu();

    // 0.exit
    void ExitSystem();
    // 1.add
    void Add_Emp();
    // 2.show
    void Show_Emp();
    // 3.Del
    void Del_Emp();
    //判断职工是否存在
    //如果存在返回职工所在数组的位置,不存在则返回-1
    int IsExist(int id);
    //保存文件
    void save();
    //统计文件中的人数
    int get_EmpNum();
    //初始化员工
    void init_Emp();
    //判断文件是否为空的flag
    bool m_FileIsEmp;
    //记录职工人数
    int m_EmpNum;
    //职工数组指针
    Worker** m_EmpArray;
};

#endif //MANAGE_SYSTEM_WORKERMANAGER_H
