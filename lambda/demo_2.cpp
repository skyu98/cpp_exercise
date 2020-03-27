/*
Q:捕捉列表能做什么呢？

这个例子里面我们使用了两个最常用的捕捉方法，
[=] 表示按照值传递的方法捕捉父作用域的所有变量，
[&] 表示按照引用传递的方法捕捉父作用域的所有变量。
如果想要捕捉特定的变量，可以直接写 [var] 或 [&var]
你甚至可以捕捉 this 指针，如果父作用域中存在的话
*/

#include <iostream>

using namespace std;

int main()
{
    int j = 1;
    auto by_val_lambda = [=]{ return j + 1; };
    auto by_ref_lambda = [&]{ return j + 1; };
    auto print = [=]{
        cout << "print by val lambda: " << by_val_lambda() << ", ";
        cout << "by ref lambda: " << by_ref_lambda() << endl;
    };
    print();
    j += 10; 
    print();
    return 0;
}