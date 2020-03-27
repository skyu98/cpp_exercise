/*
虚函数是产生了个vptr
*/

#include <iostream>
using namespace std;

class A{
public:
    virtual void func1(){}
    virtual void func2(){}
};
//B 类为空，那么大小应该是1 字节，实际情况是这样吗？
class B : public A{};

void test(){
    cout << "A size:" << sizeof(A) << endl;
    cout << "B size:" << sizeof(B) << endl;
}

int main(){
    test();
}