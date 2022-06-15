//
// Created by Alessandro on 15/06/2022.
//

#ifndef SHOPPINGLIST_CLIENT_H
#define SHOPPINGLIST_CLIENT_H

#include "Subject.h"
#include "Observer.h"
#include "ShoppingList.h"

using namespace std;

class Client : public Observer{

public:

    Client():listChanged{false}{};

    void update() override{
        listChanged = true;
    }

private:
    bool listChanged;
    list<shared_ptr<Observer>> shoppingLists;
};


#endif //SHOPPINGLIST_CLIENT_H
