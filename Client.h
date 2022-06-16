//
// Created by Alessandro on 15/06/2022.
//

#ifndef SHOPPINGLIST_CLIENT_H
#define SHOPPINGLIST_CLIENT_H

#include <iostream>
#include "Subject.h"
#include "Observer.h"
#include "ShoppingList.h"
#include "gtest/gtest.h"

using namespace std;

class Client : public Observer{

public:

    explicit Client(string n = ""): name(move(n)){
        shoppingLists = {};
    };

    void update(string list) override{
        cout << "List " << list << " has been modified." << endl;
    }

    shared_ptr<ShoppingList> findList(string listName) const;

    void addProductToList(string listName, Product* product, int quantity) const;

    void removeProductFromList(string listName, Product* product, int quantity) const;

    void addList(shared_ptr<ShoppingList>& list);

    ~Client(){
        for(auto const& i : shoppingLists)
            i->removeObserver(this);
    }

private:

    string name;
    list<shared_ptr<ShoppingList>> shoppingLists;

};


#endif //SHOPPINGLIST_CLIENT_H
