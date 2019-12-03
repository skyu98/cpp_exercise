//
// Created by Frank on 2019-12-03.
//

#include "employee.h"

Employee::Employee(int id, string name, int dId){
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

Employee::~Employee(){
    cout << "Employee destructor" << endl;
}

void Employee::showInfo(){
    cout << "employee id: " << this->m_Id
        << "\t employee name: " << this->m_Name
        << "\t position: " << this->getDeptName()
        << "\t duty: Finish manager's requirement" << endl;
}

string Employee::getDeptName(){
    return string("Employee");
}

