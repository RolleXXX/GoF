#include"Calculate.h"
#include<iostream>

int main() {
    double num1, num2;
    char op;
    std::cout << "请输入两个操作数和一个运算符（例如：1 + 2）：" << std::endl;
    std::cin >> num1 >> op >> num2;
    Calculate calculator(num1, num2, op);
    std::cout << "计算结果为：" << calculator.getResult() << std::endl;
    return 0;
}
