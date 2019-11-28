
// 封装函数显示界面,如 void showMenu()
// 在main函数中调用封装好的函数

#include <iostream>
#include <string>

using namespace std;
#define MAX 1000

// 设计联系人的结构体
struct Person{
    //name
    string m_Name;
    //sex 1. man 2. woman
    int m_Sex;
    //age
    int m_Age;
    //phone
    string m_Phone;
    //address
    string m_Addr;

};

// 设计通讯录的结构体
struct Addressbooks{
    //通讯录保存的联系人数组,(可考虑换成链表or变长数组)
    struct Person personArray[MAX];
    //通讯录中记录当前联系人个数
    int m_Size;
};

// 1. add
void addPerson(Addressbooks* abs){
    // 判断通信录是否满了，如果满了就不要再添加
    if(abs->m_Size == MAX){
        cout << "address book is already full!!! We can't add any more!" << endl;
        return;
    }else{
        //添加具体联系人

        //姓名
        string name;
        cout << "Please input the name: " << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;
        //性别
        int sex = 0;
        cout << "Please input the sex" <<endl;
        cout << "1 . man\t2. woman" << endl;
        while(true){
            cin >> sex;
            // 如果输入的是1，2可以退出循环，因为输入的是正确值
            // 如果输入有误，重新输入
            if(sex == 1 || sex == 2){
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "input error, please input again" << endl;
        }
        //年龄
        cout << "Please input the age" << endl;
        int age = 0;
        while(true){
            cin >> age;
            if(age > 0 && age <= 100){
                abs->personArray[abs->m_Size].m_Age = age;
                break;
            }
            cout << "Input error, please input again" << endl;
        }
        //电话
        cout << "Please input your phone number" << endl;
        string phone;
        while(true){
            cin >> phone;
            if(phone.length() == 11){
                abs->personArray[abs->m_Size].m_Phone = phone;
                break;
            }
            cout << "Input error, Please input again" << endl;
        }

        //地址
        cout << "Please input your home address" << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        // 增加人数后，个数记录也要增加
        abs->m_Size++;

        cout << "Add successfully!" << endl;

        //清屏动作
        system("read");
        system("clear");
    }
}

// 2. 显示所有的联系人

void showPerson(Addressbooks* abs){
    //判断通讯录中人数是否为0，如果为0，提示记录为空
    //如果不为0，显示记录的显示人信息
    if(abs->m_Size == 0){
        cout << "当前记录为空" << endl;
    }else{
        for(int i =0; i < abs->m_Size; i++){
            cout << "name: " << abs->personArray[i].m_Name << "\t";
            cout << "Sex: " << (abs->personArray[i].m_Sex == 1? "Man": "Woman") << "\t";
            cout << "Age: " << abs->personArray[i].m_Age << "\t";
            cout << "Phone: " << abs->personArray[i].m_Phone << "\t";
            cout << "Address: " << abs->personArray[i].m_Addr << endl;
        }
    }
    system("read");
    system("clear");
}

//检测联系人是否存在，如果存在，返回联系人具体位置，否则-1
//参数1 通讯录 参数2 对比姓名

int isExist(Addressbooks* abs, string name){
    for(int i = 0; i < abs->m_Size; i++){
        if(abs->personArray[i].m_Name == name){
            return i;
        }
    }
    return -1;  // 如果遍历结束都未找到，则返回-1
}

// 3. 删除联系人
void deletePerson(Addressbooks* abs){
    cout << "请输入您要删除的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if(ret != -1){
        for(int i = ret; i < abs->m_Size; i++){
            //数据前移
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;  // 更新通讯录中的人员数
        cout << "delete sucessfully" << endl;
    }else{
        cout << "This person doesn't exist" << endl;
    }
    system("read");
    system("clear");
}

//4. 查找联系人
void findPerson(Addressbooks* abs){
    cout << "Please input the person you want to find " << endl;
    string name;
    cin >> name;

    //判断指定的联系人是否存在通信录中
    int ret = isExist(abs,name);
    if(ret != -1){
        cout << "Name:" << abs->personArray[ret].m_Name << "\t";
        cout << "Sex:" << abs->personArray[ret].m_Sex << "\t";
        cout << "Age:" << abs->personArray[ret].m_Age << "\t";
        cout << "phone:" << abs->personArray[ret].m_Phone << "\t";
        cout << "Address:" << abs->personArray[ret].m_Addr << endl;

    }else{
        cout << "This person dosen't exist " << endl;
    }
    system("read");
    system("clear");
}

// 5. 修改指定人信息
void modifyPerson(Addressbooks* abs){
    cout << "请输入您要修改的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs,name);
    if(ret != -1){
        // name
        string name;
        cout << "Please input the name: " << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;
        // sex
        cout << "Please input the sex: " << endl;
        cout << "1 --- man" << endl;
        cout << "2 --- woman" << endl;
        int sex = 0;
        while(true){
            cin >> sex;
            if(sex == 1 || sex == 2){
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            cout<< "Input error, please input again" << endl;
        }
        // age
        cout << "Please input the age: " << endl;
        int age = 0;
        while(true) {
            cin >> age;
            if (age > 0 || age < 100) {
                abs->personArray[ret].m_Age = age;
                break;
            } else {
                cout << "Input error, please input again" << endl;
            }
        }
        // phone
        cout << "Please input the phone: " << endl;
        string phone;
        while(true){
            cin >> phone;
            if(phone.length() == 11){
                abs->personArray[ret].m_Phone = phone;
                break;
            }else{
                cout << "Phone number is error, please input again" << endl;
            }
        }
        // address
        cout << "Please input the address:" << endl;
        string address;
        cin >> address;
        abs->personArray[ret].m_Addr = address;

        cout << "Modify successfully!!! " << endl;
    }else{
        cout << "This person doesn't exist" << endl;
    }
    system("read");
    system("clear");

}

// 6. 清空所有联系人
void cleanPerson(Addressbooks* abs){
    abs->m_Size = 0; // 逻辑清空
    cout << "clear all successfully!!!" << endl;
    system("read");
    system("clear");
}
// 菜单界面

void showMenu(){
    cout << "***********************" << endl;
    cout << "*****  1. add     *****" << endl;
    cout << "*****  2. show    *****" << endl;
    cout << "*****  3. delete  *****" << endl;
    cout << "*****  4. find    *****" << endl;
    cout << "*****  5. change  *****" << endl;
    cout << "*****  6. clear   *****" << endl;
    cout << "*****  0. quit    *****" << endl;
    cout << "***********************" << endl;
}


int main() {


    // 创建一个通讯录结构体变量
    Addressbooks abs;
    // 初始化当前人数
    abs.m_Size = 0;


    int select = 0; // 创建用户选选择输入的变量

    while(true){
        //菜单的调用显示
        showMenu();
        cin >> select;

        switch(select){
            case 1:  // 1. add
                addPerson(&abs);  //利用地址传递，可以修饰实参
                break;
            case 2:  // 2. show
                showPerson(&abs);
                break;
            case 3:  // 3. delete
//            {
////                cout << "Please input the name to del:" << endl;
////                string name;
////                cin >> name;
////                if (isExist(&abs, name) == -1) {
////                    cout << "Dosen't has this person" << endl;
////                } else {
////                    cout << "This person exists" << endl;
////                }
////            }  //注意这个代码段
                deletePerson(&abs);
                break;
            case 4:  // 4. find
                findPerson(&abs);
                break;
            case 5:  // 5. change
                modifyPerson(&abs);
                break;
            case 6:  // 6. clear
                cleanPerson(&abs);
                break;
            case 0:  // 0. quit
                cout << "Goodbye!!!" << endl;
                system("read");
                return 0;
                break;
            default:
                break;
        }

    }

    system("read");    // 注意 system("pause");是dos里的命令
    return 0;
}