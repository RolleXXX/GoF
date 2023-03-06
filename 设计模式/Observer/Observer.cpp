#include <iostream>
#include <string>
#include <vector>

/*
假设你正在设计一个计算器应用程序，该应用程序需要支持多种输入方式（例如，使用按钮、键盘、语音等），并且需要能够显示计算结果。

使用观察者模式设计一个可扩展的计算器应用程序，以支持多种输入方式并显示计算结果。

要求：

请使用C++编程语言实现观察者模式。

要求程序能够支持任意数量的输入方式，并且可以添加新的输入方式，而不会影响到现有代码。

程序需要能够实时地显示计算结果。

请在实现代码后，编写一段测试代码来验证观察者模式的正确性。

提示：可以将计算结果作为Subject，各种输入方式作为Observer，当计算结果发生变化时，通知所有的Observer更新界面。

*/


// 前置声明
class Subject;

// 抽象观察者类
class Observer {
public:
    virtual ~Observer() {}
    virtual void update(Subject* subject) = 0;
};

// 抽象主题类
class Subject {
public:
    virtual ~Subject() {}
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify() = 0;
};

// 具体主题类
class Calculator : public Subject {
public:
    Calculator() : m_result(0) {}

    void setResult(double result) {
        m_result = result;
        notify();
    }

    double getResult() const {
        return m_result;
    }

    void attach(Observer* observer) override {
        m_observers.push_back(observer);
    }

    void detach(Observer* observer) override {
        for (auto it = m_observers.begin(); it != m_observers.end(); ++it) {
            if (*it == observer) {
                m_observers.erase(it);
                break;
            }
        }
    }

    void notify() override {
        for (auto observer : m_observers) {
            observer->update(this);
        }
    }

private:
    double m_result;
    std::vector<Observer*> m_observers;
};

// 具体观察者类
class InputMethod : public Observer {
public:
    InputMethod(const std::string& name) : m_name(name) {}

    void update(Subject* subject) override {
        std::cout << m_name << " updated. Result = " << static_cast<Calculator*>(subject)->getResult() << std::endl;
    }

private:
    std::string m_name;
};

int main() {
    Calculator calculator;

    InputMethod *buttonInput = new InputMethod("Button");
    InputMethod *keyboardInput = new InputMethod("Keyboard");
    InputMethod *voiceInput = new InputMethod("Voice");

    calculator.attach(buttonInput);
    calculator.attach(keyboardInput);
    calculator.attach(voiceInput);

    calculator.setResult(42.0);

    calculator.detach(buttonInput);
    calculator.detach(keyboardInput);

    calculator.setResult(123.45);

    calculator.attach(buttonInput);

    calculator.setResult(67.89);
    return 0;
}

/*
观察者模式是一种行为型设计模式，它定义了对象间一种一对多的依赖关系，使得当一个对象的状态发生改变时，所有依赖它的对象都会得到通知并自动更新。

观察者模式的主要特点如下：

1.主题类和观察者类是松耦合的，它们之间只有一个抽象的接口。

2.主题类可以有任意数量的观察者，可以动态地添加或删除观察者。

3.当主题类的状态发生改变时，所有的观察者都会收到通知并自动更新。

4.观察者模式支持广播通信，可以使得一个主题对象将消息传递给所有的观察者。

观察者模式的主要应用场景如下：

1.当一个对象的改变需要同时改变其它对象的时候，可以考虑使用观察者模式。

2.当一个抽象模型有两个方面，其中一个方面依赖于另一个方面，可以考虑使用观察者模式。

3.当一个对象必须通知其它对象，但是不希望这些对象和该对象发生紧耦合关系时，可以考虑使用观察者模式。

在上述例子中，计算器应用程序是主题类，多种输入方式是观察者类。当计算结果发生改变时，主题类会通知所有观察者对象更新界面。
该例子还展示了如何动态添加和删除观察者对象，以及如何实现广播通信。
*/

