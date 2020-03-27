/*
多态

向上类型转换及问题
*/

#include <iostream>
using namespace std;

class Animal{
public:
    virtual void speak(){
        cout << "动物在唱歌..." << endl;
    }
};

class Dog : public Animal{
public:
    virtual void speak(){
        cout << "小狗在唱歌..." << endl;
    }
};

void DoBussiness(Animal& animal){
    animal.speak();
}

void test(){
    Dog dog;
    DoBussiness(dog);
}

int main(){
    test();
    return 0;
}
