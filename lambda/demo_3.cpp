/*
Q:如何递归调用一个 lambda
提前声明这个称呼 fact 然后再用 [&fact] 捕捉他
std::function<int(int)> 预先声明了一个函数名 fact，然后再用引用传递捕捉他，从而实现了递归调用

BUT BUT BUT 
这里有问题，what problem?
*/

#include <iostream>
#include <functional>

using namespace std;

int main()
{
    std::function<int(int)> fact;
    fact = [&fact](int x)->int{ return x <= 1 ? x : x * fact(x - 1); };
    cout << fact(5) << endl; // => 120

    std::function<int(int, int)> gcd = [&](int a, int b)->int{
        return b == 0 ? a : gcd(b, a % b);
    };
    cout << gcd(24, 36) << endl; // => 12
    return 0;
}
