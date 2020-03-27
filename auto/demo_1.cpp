/*
auto的一些问题
auto可能得不到你预想的类型
https://www.zhihu.com/question/35517805
*/

#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

int main(){
    vector<bool> v;
    v.push_back(true);
    // 它的[]返回的不是bool，是一个表示单独bool引用的proxy class
    // auto var = v[0];
    auto var = static_cast<bool>(v[0]);

    cout << typeid(var).name() << endl;
}