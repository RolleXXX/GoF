#ifndef __FACTORY__
#define __FACTORY__


#include"Operation.h"

//工厂类
class Factory{
public:
    virtual Operation *createOperation() = 0;
};


//具体工厂
class AddFactory:public Factory{
public:
    virtual Operation *createOperation() override;
};

class SubFactory:public Factory{
public:
    virtual Operation *createOperation() override;
};

class MulFactory:public Factory{
public:
    virtual Operation *createOperation() override;
};

class DivFactory:public Factory{
public:
    virtual Operation *createOperation() override;
};

#endif