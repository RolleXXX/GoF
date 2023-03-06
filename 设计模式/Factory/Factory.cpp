#include"Factory.h"

Operation* AddFactory::createOperation(){
    return new AddOperation();
}

Operation* SubFactory::createOperation(){
    return new SubOperation();
}

Operation* MulFactory::createOperation(){
    return new MulOperation();
}

Operation* DivFactory::createOperation(){
    return new DivOperation();
}