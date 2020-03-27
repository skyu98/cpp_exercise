/*
mutable
->return-type 是一个整体
*/

#include <iostream>
using namespace std;

int main(){
    int a = 1;    
    // error
    // auto b = [=] mutable{ a = 99; };
    // auto b = [&]() { a = 99;  };
    auto b = [=]() mutable{ a = 99; };
    b();
    cout << a << endl;
    return 0;
}