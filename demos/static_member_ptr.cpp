/*
指向静态成员的指针
*/

#include <iostream>
using namespace std;

class A{
public:
    static void dis(){
        cout << data << endl;
    }
    static int data;
};

int A::data = 100;

void test(){
    int *p = &A::data;
    cout << *p << endl;
    void(*pfunc)() = &A::dis;
    pfunc();
}

int main(){
    test();
    return 0;
}