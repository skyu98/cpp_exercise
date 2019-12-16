#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

int main() {

//    // test section
//    Worker* worker = NULL;
//    worker = new Employee(1, "Frank", 1);
//    worker->showInfo();
//    delete worker;  // important,be careful
//
//    worker = new Manager(2, "chanchan", 2);
//    worker->showInfo();
//    delete worker; //要有delete就要有析构函数
//
//    worker = new Boss(3, "April", 3);
//    worker->showInfo();
//    delete worker; //new和delete成对出现

    WorkerManager wm;
    int choice = 0;
    while(true){
        wm.Show_Menu();

        cout << "Please input your choice:" << endl;
        cin >> choice;
        switch(choice){
            case 0:  // Exit
                wm.ExitSystem();
                break;
            case 1:  // add
                wm.Add_Emp();
                break;
            case 2:  // show
                wm.Show_Emp();
                break;
            case 3:  // delete
            {  // TEST code
                int ret = wm.IsExist(1);
                if(ret != -1){
                    cout << "Employee exists" << endl;
                }else{
                    cout << "Employee dosen't exist" << endl;
                }
                break;
            }
            case 4:  // edit
                break;
            case 5:  // find
                break;
            case 6:  // sort
                break;
            case 7:  // clear
                break;
            default:
                system("clear");
                break;
        }
    }
    system("read");

    return 0;
}