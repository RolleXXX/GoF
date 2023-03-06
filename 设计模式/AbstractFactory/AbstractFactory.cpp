/*
假设你正在设计一款电子游戏，该游戏需要实现不同类型的怪物，并且每种怪物有不同的属性，比如攻击力、防御力、生命值等。
现在请你使用抽象工厂模式来设计一个怪物生成器，能够生成不同类型的怪物，并且能够根据需要调整每种怪物的属性。

请根据上述要求，使用C++语言实现一个怪物生成器，包括以下组件：

抽象怪物类（Monster），包括攻击力、防御力和生命值等属性，以及一个纯虚函数display()，用于显示怪物的信息。

具体怪物类（如Slime、Goblin、Dragon等），继承自抽象怪物类，并实现display()函数，用于显示自己的信息。

抽象工厂类（MonsterFactory），包括创建不同类型的怪物的纯虚函数createMonster()。

具体工厂类（如SlimeFactory、GoblinFactory、DragonFactory等），继承自抽象工厂类，实现createMonster()函数，用于创建对应的具体怪物对象。
*/


#include <iostream>
#include <string>
using namespace std;

//抽象怪物类
class Monster{
public:
    virtual void display() = 0;
    virtual ~Monster(){}
protected:
    int m_attack;
    int m_defense;
    int m_hp;
};

//具体怪物类：史莱姆
class Slime:public Monster{
public:
    Slime(){
        m_attack = 10;
        m_defense = 5;
        m_hp = 20;
    }
    virtual void display() override{
        cout << "This is a Slime. Attack: " << m_attack << ", Defense: " << m_defense << ", HP: " << m_hp << endl;
    }
};

// 具体怪物类：哥布林
class Goblin : public Monster {
public:
    Goblin() {
        m_attack = 20;
        m_defense = 10;
        m_hp = 40;
    }
    virtual void display() {
        cout << "This is a Goblin. Attack: " << m_attack << ", Defense: " << m_defense << ", HP: " << m_hp << endl;
    }
};

// 具体怪物类：巨龙
class Dragon : public Monster {
public:
    Dragon() {
        m_attack = 50;
        m_defense = 30;
        m_hp = 100;
    }
    virtual void display() {
        cout << "This is a Dragon. Attack: " << m_attack << ", Defense: " << m_defense << ", HP: " << m_hp << endl;
    }
};


//抽象工厂类
class MonsterFactory{
public:
    virtual Monster* createMonster() = 0;
    virtual ~MonsterFactory(){}
};

//具体工厂类：史莱姆
class SlimeFactory : public MonsterFactory {
public:
    virtual Monster* createMonster() {
        return new Slime();
    }   
};

// 具体工厂类：哥布林工厂
class GoblinFactory : public MonsterFactory {
public:
    virtual Monster* createMonster() {
        return new Goblin();
    }
};

// 具体工厂类：巨龙工厂
class DragonFactory : public MonsterFactory {
public:
virtual Monster* createMonster() {
        return new Dragon();
    }
};

int main() {
    // 创建史莱姆工厂并生成史莱姆
    MonsterFactory* slimeFactory = new SlimeFactory();
    Monster* slime = slimeFactory->createMonster();
    slime->display();


    // 创建哥布林工厂并生成哥布林
    MonsterFactory* goblinFactory = new GoblinFactory();
    Monster* goblin = goblinFactory->createMonster();
    goblin->display();

    // 创建巨龙工厂并生成巨龙
    MonsterFactory* dragonFactory = new DragonFactory();
    Monster* dragon = dragonFactory->createMonster();
    dragon->display();

    // 释放资源
    delete slime;
    delete slimeFactory;
    delete goblin;
    delete goblinFactory;
    delete dragon;
    delete dragonFactory;

    return 0;
}

/*
在抽象工厂模式中，每个具体工厂类负责创建一组相关的产品对象，因此需要定义多个具体工厂类。而在简单工厂模式中，只需要定义一个静态工厂方法就可以创建所有的产品对象。

在这个例子中，我们定义了三个具体工厂类：SlimeFactory、GoblinFactory和DragonFactory，每个工厂类负责创建对应的怪物对象。因此，这个例子符合抽象工厂模式的特点。

在抽象工厂模式中，客户端需要先实例化一个具体的工厂类对象，再调用它的工厂方法来创建所需的对象。而在简单工厂模式中，客户端只需要调用一个静态工厂方法即可创建所需的对象。
*/