//
// Created by Alessandro on 15/06/2022.
//

#ifndef SHOPPINGLIST_CLIENT_H
#define SHOPPINGLIST_CLIENT_H

#include "Subject.h"
#include "Observer.h"
#include "ShoppingList.h"

using namespace std;

class Client : public Subject{

public:
    virtual void registerObserver(shared_ptr<Observer> o) override{
        shoppingLists.push_back(o);
    }

    virtual void removeObserver(shared_ptr<Observer> o) override{
        shoppingLists.remove(o);
    }

    virtual void notifyObserver(shared_ptr<Observer> o) override{
        o->update();
    }

private:
    list<shared_ptr<Observer>> shoppingLists;

};


#endif //SHOPPINGLIST_CLIENT_H
