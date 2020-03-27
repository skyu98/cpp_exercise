/*

*/

#include <iostream>
using namespace std;

class Base{
public:
    void func1(){
        cout << "Base::void func1()" << endl;
    }
    void func1(int param){
        cout << "Base::void func1(int param)" << endl;
    }
    void myfunc(){
        cout << "Base::void myfunc()" << endl;
    }
};

class Derived1 : public Base{
public:
    void myfunc(){
        cout << "Derived1::void myfunc()" << endl;
    }
};

class Derived2 : public Base{
public:
    //改变成员函数的参数列表
    void func1(int param1, int param2){
        cout << "Derived2::void func1(int param1,int param2)" << endl;
    };
};

class Derived3 : public Base{
public:
//改变成员函数的返回值
    int func1(int param){
        cout << "Derived3::int func1(int param)" << endl;
        return 0;
    }
};

int main(){
    Derived1 derived1;
    derived1.func1();
    derived1.func1(20);
    derived1.myfunc();
    cout << "-------------" << endl;
    Derived2 derived2;
    //derived2.func1(); //func1 被隐藏
    //derived2.func1(20); //func2 被隐藏
    derived2.func1(10,20); //重载func1 之后，基类的函数被隐藏
    derived2.myfunc();
    cout << "-------------" << endl;
    Derived3 derived3;
    //derived3.func1(); 没有重新定义的重载版本被隐藏
    derived3.func1(20);
    derived3.myfunc();
    return EXIT_SUCCESS;
}