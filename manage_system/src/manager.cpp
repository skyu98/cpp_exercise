//
// Created by Frank on 2019-12-03.
//
#include "manager.h"

Manager::Manager(int id, string name, int dId){
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

Manager::~Manager(){
    cout << "Manager destructor" << endl;
}

void Manager::showInfo(){
    cout << "employee id: " << this->m_Id
         << "\t employee name: " << this->m_Name
         << "\t position: " << this->getDeptName()
         << "\t duty: Finish boss's requirement and hand out the "
         << "projects to the employees" << endl;
}

string Manager::getDeptName(){
     return string("Manager");
}

