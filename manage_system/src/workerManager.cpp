//
// Created by Frank on 2019-11-29.
//

#include "workerManager.h"

WorkerManager::WorkerManager(){
    cout << "This is workerManager constructor!!" << endl;
    // init
    this->m_EmpNum = 0;
    this->m_EmpArray = NULL;
}

WorkerManager::~WorkerManager(){
    cout << "This is workerManager destructor!!" << endl;
}

void WorkerManager::Show_Menu(){
    cout << "*********************************************" << endl;
    cout << "****  Welcome to our management system     ** " << endl;
    cout << "****************  0.exit  *******************" << endl;
    cout << "****************  1.add   *******************"<< endl;
    cout << "****************  2.show  *******************" << endl;
    cout << "****************  3.delete  *****************" << endl;
    cout << "****************  4.edit  *******************" << endl;
    cout << "****************  5.find  *******************" << endl;
    cout << "****************  6.sort by idx  ************" << endl;
    cout << "****************  7.clear all  **************" << endl;
    cout << "*********************************************" << endl;
    cout << endl;
}

void WorkerManager::ExitSystem() {
    cout << "GoodBye!!" << endl;
    system("read");
    exit(0);
}

void WorkerManager::Add_Emp() {
    cout << "How many workers to add ? " << endl;
    int addNum = 0;
    cin >> addNum;
    if(addNum > 0){
        // 计算添加新空间大小
        int newSize = this->m_EmpNum + addNum;
        // 开辟新空间
        Worker** newSpace = new Worker*[newSize];
        // 将原来的空间下的数据拷贝到新空间下
        if(this->m_EmpArray != NULL){
            for(int i = 0; i < this->m_EmpNum; i++){
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        for(int i = 0; i < addNum; i++){
            int id;
            string name;
            int dSelect; // 部门选择

            cout << "Please input " << i << " id" << endl;
            cin >> id;
            cout << "Please input " << i << " name" << endl;
            cin >> name;
            cout << "Please input " << i << " position" << endl;
            co
        }
    }else{
        cout << "Input error" << endl;
    }
}