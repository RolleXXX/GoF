//初始化列表的好处
/*
在构造函数体中使用赋值语句来初始化成员变量，编译器会先调用默认构造函数来创建对象，然后再赋值。
而如果使用初始化列表，编译器会直接调用成员变量的构造函数来创建对象，从而避免了一次不必要的构造和赋值
*/


#include<iostream>
//当我们定义一个成员变量时，如果没有使用初始化列表初始化该成员变量，那么在对象被创建时会默认调用该成员变量的默认构造函数来进行初始化


class B {
public:
    B() { std::cout << "B()" << std::endl; }
    B(int n) { std::cout << "B(" << n << ")" << std::endl; }
};

class A {
public:
    A() : m_n(0) {
        m_b = B(1);//2.调用B的带整型参数的构造函数生成一个临时对象，在把这个临时对象赋值给m_b
        std::cout << "A()" << std::endl;
        
    }

private:
    B m_b;//1.先用B的默认构造函数创建一个m_b
    int m_n;
};



class C {
public:
    //直接调用B(int n)这个构造函数来生成m_b
    C() : m_b(1),m_n(0) {
        
        std::cout << "A()" << std::endl;
        
    }

private:
    B m_b;
    int m_n;
};

int main() {
    A a;
    std::cout<<std::endl;
    C c;
    return 0;
}
