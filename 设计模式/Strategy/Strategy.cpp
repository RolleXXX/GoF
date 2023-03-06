#include <iostream>
#include <string>
using namespace std;
// 抽象的角色类
class Character {
public:
    virtual void attack() = 0;
    virtual void defense() = 0;
    virtual void useSkill() = 0;
    virtual void gainExperience(int exp) = 0;
    virtual void display() = 0;
    // friend class HumanWarriorStrategy; //加上之后HumanWarriorStrategy才可以访问protected的成员
    //更好的做法是实现get和set方法 做到接口小而精
    int getAttack() const { return attack_; }
    int getDefense() const { return defense_; }
    int getHealth() const { return health_; }
    int getMana() const { return mana_; }
    std::string getSkill() const { return skill_; }

    void setAttack(int attack) { attack_ = attack; }
    void setDefense(int defense) { defense_ = defense; }
    void setHealth(int health) { health_ = health; }
    void setMana(int mana) { mana_ = mana; }
    void setSkill(std::string skill) { skill_ = skill; }

protected:
    int attack_;
    int defense_;
    int health_;
    int mana_;
    std::string skill_;
};

// 抽象的策略类
class CharacterStrategy {
public:
    virtual void setAttributes(Character* character) = 0;
    virtual void setSkills(Character* character) = 0;
};

// 具体的角色类：人族战士
class HumanWarrior : public Character {
public:
    HumanWarrior(std::string name, int level, int exp) : name_(name), level_(level), exp_(exp), strategy_(nullptr) {}

    void setStrategy(CharacterStrategy* strategy) {
        strategy_ = strategy;
        strategy_->setAttributes(this);
        strategy_->setSkills(this);
    }

    void attack() override {
        std::cout << name_ << " uses sword to attack the enemy!" << std::endl;
    }

    void defense() override {
        std::cout << name_ << " uses shield to defense!" << std::endl;
    }

    void useSkill() override {
        std::cout << name_ << " uses " << skill_ << " to cause massive damage!" << std::endl;
    }

    void gainExperience(int exp) override {
        exp_ += exp;
        if (exp_ >= 100) {
            level_++;
            exp_ -= 100;
        }
    }

    void display() override {
        std::cout << "Human warrior: " << name_ << ", level: " << level_ << ", exp: " << exp_ << ", attack: " << attack_ << ", defense: " << defense_ << ", health: " << health_ << ", mana: " << mana_ << std::endl;
    }
    
private:
    std::string name_;
    int level_;
    int exp_;
    CharacterStrategy* strategy_;

    
};

// 具体的策略类：人族战士策略
class HumanWarriorStrategy : public CharacterStrategy {
public:
    void setAttributes(Character* character) override {

        character->setAttack(50);
        character->setDefense(20);
        character->setHealth(100);
        character->setMana(20);
    }

    void setSkills(Character* character) override {

        character->setSkill("Sword Skill: Wind Strike");
    }
};

int main() {
    HumanWarrior* warrior = new HumanWarrior("Tom", 1, 0);
    warrior->display();

    CharacterStrategy* strategy = new HumanWarriorStrategy();
    warrior->setStrategy(strategy);
    warrior->display();

    warrior->attack();
    warrior->defense();
    warrior->useSkill();
    warrior->gainExperience(80);
    warrior->display();

    return 0;
}

/*
策略模式是一种行为型设计模式，它定义了一系列算法，将它们封装起来，并使它们可以相互替换。策略模式可以让算法独立于使用它的客户端而变化。在策略模式中，类之间的关系是通过接口和实现类之间的关系来实现的，客户端通过接口来调用具体实现类中的算法。

使用策略模式的场景包括：

1.在一个系统中，需要动态地在几种算法中选择一种时。
2.有多个类，它们的区别仅在于它们的行为不同时，可以使用策略模式来动态地选择类的行为。
3.需要封装算法的具体实现细节时，可以使用策略模式来隐藏算法的实现细节。

以上代码中，使用了策略模式来实现不同角色类的不同属性和技能的设置，即CharacterStrategy是策略接口，HumanWarriorStrategy是具体策略类。
通过使用不同的策略对象，可以动态地设置HumanWarrior对象的属性和技能，从而使HumanWarrior对象的行为发生变化。
通过策略模式，HumanWarrior对象和HumanWarriorStrategy对象之间的关系得以解耦，从而使得代码更加灵活可维护
*/
