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

    shared_ptr<ShoppingList> findList(string& name) {
        for (auto const &s: shoppingLists)
            if (s->getListName() == name)
                return s;
        cout << "List " << name << "not found." << endl;
        return nullptr;
    }

    void addProductToList(string& name, unique_ptr<Product> product, int quantity){
        shared_ptr<ShoppingList> s = findList(name);
        if (s != nullptr){
                s->addProduct(std::move(product), quantity);
                cout << "Product added to list " << name << "." << endl;
            }
    }

    void removeProductFromList(string& name, unique_ptr<Product> product, int quantity) {
        shared_ptr<ShoppingList> s = findList(name);
        if(s != nullptr) {
            if(s->checkProduct(product->getName()) != nullptr) {
                s->removeProduct(std::move(product), quantity);
                cout << "Product removed from list " << name << endl;
            }
        }
    }

private:
    list<shared_ptr<ShoppingList>> shoppingLists;
};


#endif //SHOPPINGLIST_CLIENT_H
