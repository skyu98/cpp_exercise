//
// Created by Frank on 2019-11-29.
//

#include "workerManager.h"

WorkerManager::WorkerManager(){
    cout << "This is workerManager constructor!!" << endl;
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