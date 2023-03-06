/*
题目描述：

设计一个类，要求该类为单例模式，同时提供一个静态方法getInstance()来获取该单例实例。
*/

/*
需要考虑线程安全的问题，注意不能用双检查锁。
C++11还提供了一种更加优雅的实现方式，即使用局部静态变量。
在这种方式中，getInstance()方法中的局部静态变量在程序的整个生命周期内只会被初始化一次。
由于静态局部变量在编译时就已经被初始化，因此不需要加锁保证线程安全
*/


#include<iostream>
#include<mutex>

class Singleton{
public:
    static Singleton* getInstance(){
        static Singleton instance;
        return &instance;
    }

    void showMessage(){
        std::cout << "Hello!" << std::endl;
    }

private:
    Singleton(){}
    Singleton(const Singleton& other){}
    Singleton& operator=(const Singleton &other){}
};

int main(){
    Singleton *s1 = Singleton::getInstance();
    s1->showMessage();

    Singleton *s2 = Singleton::getInstance();
    s2->showMessage();

    if(s1==s2){
        std::cout << "s1 and s2 are the same instance" << std::endl;
    }
}