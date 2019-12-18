//
// Created by Frank on 2019-12-17.
//

#ifndef MINIDL_SHAPE_H
#define MINIDL_SHAPE_H
#include <vector>
namespace MiniDL{
    class Shape{
    public:
        Shape();
        ~Shape();
    public:
        int get_dim(const int index);
    private:
        std::vector<int> data;
    };
}// namespace MiniDL


#endif //MINIDL_SHAPE_H
