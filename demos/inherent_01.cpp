/*
为什么我们需要继承

下面是我们没有用继承的时候，很多代码都需要在写一次
*/
#include <iostream>
using namespace std;

class IndexPage{
public:
    //网页头部
    void Header(){
        cout << "网页头部!" << endl;
    }
    //网页左侧菜单
    void LeftNavigation(){
        cout << "左侧导航菜单!" << endl;
    }
    //网页主体部分
    void MainBody(){
        cout << "首页网页主题内容!" << endl;
    }
    //网页底部
    void Footer(){
        cout << "网页底部!" << endl;
    }
private:
    string mTitle; //网页标题
};

//如果不使用继承，那么定义新闻页类，需要重新写一遍已经有的代码
class NewsPage{
public:
    //网页头部
    void Header(){
        cout << "网页头部!" << endl;
    }
    //网页左侧菜单
    void LeftNavigation(){
        cout << "左侧导航菜单!" << endl;
    }
    //网页主体部分
    void MainBody(){
        cout << "新闻网页主体内容!" << endl;
    }
    //网页底部
    void Footer(){
        cout << "网页底部!" << endl;
    }
private:
    string mTitle; //网页标题
};

void test(){
    NewsPage* newspage = new NewsPage;
    newspage->Header();
    newspage->MainBody();
    newspage->LeftNavigation();
    newspage->Footer();
}

int main(){
    test();
}