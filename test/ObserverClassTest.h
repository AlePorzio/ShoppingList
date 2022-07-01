//
// Created by Alessandro on 01/07/2022.
//

#ifndef SHOPPINGLIST_OBSERVERCLASSTEST_H
#define SHOPPINGLIST_OBSERVERCLASSTEST_H

#include "../Observer.h"
#include "iostream"
#include "SubjectClassTest.h"

class ObserverClassTest : public Observer{

public:

    virtual void update(std::string lastOperation) override{
        std::cout << lastOperation << std::endl;
    };

    virtual ~ObserverClassTest(){
        for(auto const & s : subjects)
            s->removeObserver(this);
    };

private:

    list<SubjectClassTest*> subjects;

};


#endif //SHOPPINGLIST_OBSERVERCLASSTEST_H
