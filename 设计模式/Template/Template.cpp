#include<iostream>
using namespace std;

/*
假设我们要设计一个游戏，游戏中有一个"任务"类，其抽象基类如下
*/
class Task {
public:
    virtual void prepare() = 0;
    virtual void start() = 0;
    virtual void finish() = 0;

    void execute() {
        prepare();
        start();
        finish();
    }
};

/*
现在，我们要派生出两个具体的任务类：

采矿任务（MiningTask）：prepare()方法中准备采矿设备；start()方法中采矿；finish()方法中清理采矿设备。
打怪任务（FightingTask）：prepare()方法中准备武器和防具；start()方法中打怪；finish()方法中清理武器和防具。
请根据上述要求，完成该任务类的设计
*/

class MiningTask:public Task{
public:
    virtual void prepare() override{
        cout << "准备采矿设备" << endl;
    }
    virtual void start() override{
        cout << "进行采矿" << endl;
    }
    virtual void finish() override{
        cout << "清理采矿设备" << endl;
    }
};

class FightingTask:public Task{
public:
    virtual void prepare() override{
        cout << "带上头盔和剑" << endl;
    }
    virtual void start() override{
        cout << "打怪" << endl;
    }
    virtual void finish() override{
        cout << "清理头盔和剑" << endl;
    }
};

int main(){
    Task* task1= new MiningTask();
    Task* task2= new FightingTask();
    task1->execute();
    task2->execute();
}

//模板方法很常见也很简单但是也很实用，就是多态。主要用于在固定流程下实现某些步骤的特殊方法