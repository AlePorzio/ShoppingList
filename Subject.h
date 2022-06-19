//
// Created by Alessandro on 15/06/2022.
//

#ifndef SHOPPINGLIST_SUBJECT_H
#define SHOPPINGLIST_SUBJECT_H

#include <memory>
#include <list>
#include "Observer.h"

using namespace std;

class Subject {

public:

    virtual void registerObserver(Observer* o) = 0;

    virtual void removeObserver(Observer* o) = 0;

    virtual void notifyObserver() = 0;

    virtual ~Subject(){};

};


#endif //SHOPPINGLIST_SUBJECT_H
