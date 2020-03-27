/*
https://zhuanlan.zhihu.com/p/45430715
lambda 格式:
auto a_alias = [capture](parameters)->return_type{ ... };
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    auto addition = [](int _1, int _2)->int{ return _1 + _2; };
    vector<int> a = { 1, 2, 3, 4, 5 };
    vector<int> b = { 6, 7, 8, 9, 10 };
    for (int i = 0, sz = a.size(); i < sz; i++)
    {
        a[i] = addition(a[i], b[i]);
    }
    for (auto e : a) cout << " " << e; cout << endl;
    // => 7 9 11 13 15
    return 0;
}
