//
// Created by Frank on 2019-12-03.
//
#include "boss.h"

Boss::Boss(int id, string name, int dId){
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

Boss::~Boss(){
    cout << "Boss destructor" << endl;
};

void Boss::showInfo(){
    cout << "employee id: " << this->m_Id
         << "\t employee name: " << this->m_Name
         << "\t position: " << this->getDeptName()
         << "\t duty: Manage the company" << endl;
}

string Boss::getDeptName(){
    return string("Boss");
}


