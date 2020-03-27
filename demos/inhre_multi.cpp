/*
菱形继承
*/

#include <iostream>
using namespace std;
class BigBase{
public:
    BigBase(){ mParam = 0; }
    void func(){ cout << "BigBase::func" << endl; }
public:
    int mParam;
};

class Base1 : public BigBase{};
class Base2 : public BigBase{};
class Derived : public Base1, public Base2{};

int main(){
    Derived derived;
    //1. 对“func”的访问不明确
    //derived.func();
    //cout << derived.mParam << endl;
    cout << "derived.Base1::mParam:" << derived.Base1::mParam << endl;
    cout << "derived.Base2::mParam:" << derived.Base2::mParam << endl;
    //2. 重复继承
    cout << "Derived size:" << sizeof(Derived) << endl; //8
    return EXIT_SUCCESS;
}