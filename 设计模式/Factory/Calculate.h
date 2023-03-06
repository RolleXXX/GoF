#ifndef __CALCULATE__
#define __CALCULATE__


#include<iostream>
#include"Operation.h"
#include"Factory.h"
using namespace std;

class Calculate{
public:
    Calculate(double num1, double num2, char op);
    double getResult();

private:
    double num1_;
    double num2_;
    char op_;
    Operation *operation_;
};

#endif