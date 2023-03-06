#include "Calculate.h"

Calculate::Calculate(double num1, double num2, char op) {
    num1_ = num1;
    num2_ = num2;
    op_ = op;
    Factory* factory = nullptr;
    switch (op) {
        case '+':
            factory = new AddFactory();
            break;
        case '-':
            factory = new SubFactory();
            break;
        case '*':
            factory = new MulFactory();
            break;
        case '/':
            factory = new DivFactory();
            break;
        default:
            break;
    }
    if (factory) {
        operation_ = factory->createOperation();
    }
}

double Calculate::getResult(){
    return operation_->calculate(num1_,num2_);
}
