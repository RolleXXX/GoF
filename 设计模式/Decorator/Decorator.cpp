/*
假设你正在为一个家具制造商设计一个家具展示应用程序。你需要实现一个 Furniture 类，以及一些子类（如 Sofa，Chair 和 Table），这些子类都需要有自己的颜色和材料属性。

但是，客户端希望能够在不改变原有代码的情况下，随意地更改每个家具的颜色和材料属性。因此，你需要使用装饰器模式来解决这个问题。
*/


#include <iostream>
#include <string>

using namespace std;


// 抽象基类 Furniture
class Furniture
{
public:
    virtual ~Furniture() {}
    virtual string getDescription() = 0;
};

// 具体家具类
class Sofa : public Furniture
{
public:
    virtual string getDescription()
    {
        return "A sofa";
    }
};

class Chair : public Furniture
{
public:
    virtual string getDescription()
    {
        return "A chair";
    }
};

class Table : public Furniture
{
public:
    virtual string getDescription()
    {
        return "A table";
    }
};

// 装饰器基类
class Decorator : public Furniture
{
public:
    Decorator(Furniture* f) : m_furniture(f) {}
    virtual string getDescription() 
    {
        return m_furniture->getDescription();
    }
protected:
    Furniture* m_furniture;
    //当一个子类继承了一个父类，它会继承父类的公有成员和受保护成员，但是不会继承父类的私有成员
};

// 具体装饰器类
class ColorDecorator : public Decorator
{
public:
    //其中 Decorator(f) 表示调用 Decorator 类的构造函数，并将 f 作为参数传递
    //MaterialDecorator 的构造函数中，m_furniture 成员变量会被初始化为 f。
    ColorDecorator(Furniture* f, const string& color)
        : Decorator(f), m_color(color) {}

    virtual string getDescription() 
    {
        return m_furniture->getDescription() + " in " + m_color;
    }
private:
    string m_color;
};

class MaterialDecorator : public Decorator
{
public:
    MaterialDecorator(Furniture* f, const string& material)
        : Decorator(f), m_material(material) {}
    virtual string getDescription() 
    {
        return m_furniture->getDescription() + " made of " + m_material;
    }
private:
    string m_material;
};

// 客户端代码
int main()
{
    // 创建一个红色沙发
    Furniture* sofa = new Sofa();
    Furniture* redSofa = new ColorDecorator(sofa, "red");

    // 创建一个木质椅子
    Furniture* chair = new Chair();
    Furniture* woodChair = new MaterialDecorator(chair, "wood");

    // 输出沙发和椅子的描述信息
    cout << redSofa->getDescription() << endl;
    cout << woodChair->getDescription() << endl;

    // 释放内存
    delete redSofa;
    delete woodChair;

    return 0;
}
