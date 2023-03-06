#include"Operation.h"

double AddOperation::calculate(double num1,double num2){
    return num1 + num2;
}

char AddOperation::getOpreation(){
    return '+';
}

double SubOperation::calculate(double num1,double num2){
    return num1 - num2;
}

char SubOperation::getOpreation(){
    return '-';
}

double MulOperation::calculate(double num1,double num2){
    return num1 * num2;
}

char MulOperation::getOpreation(){
    return '*';
}

double DivOperation::calculate(double num1,double num2){
    return num1 / num2;
}

char DivOperation::getOpreation(){
    return '/';
}