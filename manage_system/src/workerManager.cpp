//
// Created by Frank on 2019-11-29.
//

#include "workerManager.h"

WorkerManager::WorkerManager(){
    cout << "This is workerManager constructor!!" << endl;
    // init，三种情况
    //1.文件不存在
    ifstream  ifs;
    ifs.open(FILENAME, ios::in); //读文件
    if(!ifs.is_open()){
        cout << "The file doesn't exist" << endl;
        //初始化记录人数
        this->m_EmpNum = 0;
        //初始化数组指针
        this->m_EmpArray = NULL;
        //初始化文件是否为空
        this->m_FileIsEmp = true;
        ifs.close();
        return;
    }
    //2.文件存在，但是数据为空
    char ch;
    ifs >> ch;
    if(ifs.eof()){
        //文件为空
        cout << "File is empty" << endl;
        //初始化记录人数
        this->m_EmpNum = 0;
        //初始化数组指针
        this->m_EmpArray = NULL;
        //初始化文件是否为空
        this->m_FileIsEmp = true;
        ifs.close();
        return;
    }
    //文件存在，并且不为空
    int num = this->get_EmpNum();
    cout << "The number of employers is:" << num << endl;
    this->m_EmpNum = num;
    //开辟空间
    this->m_EmpArray = new Worker*[this->m_EmpNum];
    //将文件数据，存到数组中
    this->init_Emp();
    //Test code
//    for(int i = 0; i < this->m_EmpNum; i++){
//        cout << "  ID:  " << this->m_EmpArray[i]->m_Id
//        << "  Name:  " << this->m_EmpArray[i]->m_Name
//        << "  Department ID:  " << this->m_EmpArray[i]->m_DeptId<< endl;
//    }


//    this->m_EmpNum = 0;
//    this->m_EmpArray = NULL;
}

WorkerManager::~WorkerManager(){
    cout << "This is workerManager destructor!!" << endl;
    if(this->m_EmpArray != NULL){
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
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
            cout << "1. Employee" << endl;
            cout << "2. Manager" << endl;
            cout << "3. Boss" << endl;
            cin >> dSelect;

            Worker* worker = NULL;
            switch (dSelect){
                case 1:
                    worker = new Employee(id, name, dSelect);
                    break;
                case 2:
                    worker = new Manager(id, name, dSelect);
                    break;
                case 3:
                    worker = new Boss(id, name, dSelect);
                    break;
                default:
                    break;
            }
            //将创建职工职责，保存到数组中
            newSpace[this->m_EmpNum + i] = worker;
        }

        // important: 释放原有的空间
        delete[] this->m_EmpArray;
        //更改新空间的指向
        this->m_EmpArray = newSpace;
        //更新职工人数
        this->m_EmpNum = newSize;
        //更新职工不为空的标志
        this->m_FileIsEmp = false;
        //提示添加成功
        cout << "Add " << addNum << "workers susccessfully!!" << endl;
        //保存记录到文件
        this->save();
    }else{
        cout << "Input error" << endl;
    }
    // clear
    system("read");
    system("clear");
}

void WorkerManager::save(){
    ofstream ofs;
    ofs.open(FILENAME, ios::out); //用输出方式打开文件(写文件
    //将每个人数据写入到文件
    for(int i = 0; i < this->m_EmpNum; i++){
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }
    //关闭文件
}

int WorkerManager::get_EmpNum() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in); // 打开文件，读
    int id;
    string name;
    int dId;
    int num = 0;
    while(ifs >> id && ifs >> name && ifs >> dId){
        num++;
    }
    return num;

}

void WorkerManager::init_Emp() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int dId;
    int index = 0;
    while(ifs >> id && ifs >> name && ifs >> dId){
        Worker* worker = NULL;
        if(dId == 1){ //employee
            worker = new Employee(id, name, dId);
        }else if(dId == 2){
            worker = new Manager(id, name, dId);
        }else{
            worker = new Boss(id, name, dId);
        }
        this->m_EmpArray[index++] = worker;
    }
    //关闭文件
    ifs.close();
}

void WorkerManager::Show_Emp() {
    //判断文件是否为空
    if(this->m_FileIsEmp){
        cout << "File dosen't exist or log is null" << endl;
    }else{
        for(int i = 0; i < m_EmpNum; i++){
            //利用多态调用程序接口
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("read");
    system("clear");
}

void WorkerManager::Del_Emp() {

}

int WorkerManager::IsExist(int id) {
    int index = -1;
    for(int i =  0; i < this ->m_EmpNum; i++){
        if(this->m_EmpArray[i]->m_Id == id){
            //找到职工
            index = i;
            break;
        }
    }
    return index;
}