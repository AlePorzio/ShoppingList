//
// Created by Alessandro on 01/07/2022.
//

#ifndef SHOPPINGLIST_SUBJECTCLASSTEST_H
#define SHOPPINGLIST_SUBJECTCLASSTEST_H

#include "../Subject.h"

class SubjectClassTest : public Subject{

private:

    list<Observer* > observers;
    string lastOperation = "testString";

public:

    const list<Observer *> &getObservers() const {
        return observers;
    }

    virtual void notifyObserver() override{
        for(auto const& o : observers)
            o->update(lastOperation);
    }

    virtual void registerObserver(Observer* o) override{
        observers.push_back(o);
    }

    virtual void removeObserver(Observer* o) override{
        observers.remove(o);
    }



    virtual ~SubjectClassTest(){};

};


#endif //SHOPPINGLIST_SUBJECTCLASSTEST_H
