//
// Created by Alessandro on 15/06/2022.
//

#ifndef SHOPPINGLIST_CLIENT_H
#define SHOPPINGLIST_CLIENT_H

#include <iostream>
#include "Subject.h"
#include "Observer.h"
#include "ShoppingList.h"

using namespace std;

class Client : public Observer{

public:

    void update(string list) override{
        cout << "List " << list << "has been modified." << endl;
    }

    /*void addProductToList(shared_ptr<Observer> list, unique_ptr<Product> product, int quantity){

    }*/

private:
    list<shared_ptr<Observer>> shoppingLists;
};


#endif //SHOPPINGLIST_CLIENT_H
