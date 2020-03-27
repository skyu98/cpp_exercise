/*
为什么我们需要继承

当我们使用了继承
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

//使用继承后，就只用重写不一样的部分
class NewsPage : public IndexPage{
public:
    //网页主体部分
    void MainBody(){
        cout << "新闻网页主主体内容!" << endl;
    }
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