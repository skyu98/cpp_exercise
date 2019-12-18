//
// Created by Frank on 2019-12-17.
//

#ifndef MINIDL_OPERATOR_H
#define MINIDL_OPERATOR_H

#include "Data.h"
#include <vector>
namespace MiniDL{
    // base class of Ops
    class Operator{
    public:
        Operator();
        ~Operator();
    public:
        //forwarcd of op
        virtual void forward(const std::vector<Data>& inputs
                            std::vector<Data>& outputs);
        //backward of op
        virtual void backward(std::vector<Data>& inputs,
                const std::vector<Data>& outputs);
    };
}

#endif //MINIDL_OPERATOR_H
