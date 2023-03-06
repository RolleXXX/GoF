#ifndef __OPERATION
#define __OPERATION


//抽象操作类
class Operation{
public:
    virtual double calculate(double num1, double num2) = 0;
    virtual char getOpreation() = 0;
};

class AddOperation:public Operation{
public:
    virtual double calculate(double num1, double num2) override;
    virtual char getOpreation() override;
};

class SubOperation:public Operation{
public:
    virtual double calculate(double num1, double num2) override;
    virtual char getOpreation() override;
};

class MulOperation:public Operation{
public:
    virtual double calculate(double num1, double num2) override;
    virtual char getOpreation() override;
};

class DivOperation:public Operation{
public:
    virtual double calculate(double num1, double num2) override;
    virtual char getOpreation() override;
};

#endif