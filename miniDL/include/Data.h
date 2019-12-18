//
// Created by Frank on 2019-12-17.
//

#ifndef MINIDL_DATA_H
#define MINIDL_DATA_H

#include "Shape.h"
namespace MiniDL{
    class Data{
    public:
        Data();
        ~Data();
    private:
        //shape of data
        Shape shape;
        //data container
        std::vector<float> data;
    };
} // namespace MiniDL



#endif //MINIDL_DATA_H
