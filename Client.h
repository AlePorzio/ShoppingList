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

    explicit Client(string n = ""): name(move(n)){
        //for(auto const& i: shoppingLists)
    };

    void update(string list) override{
        cout << "List " << list << "has been modified." << endl;
    }

    shared_ptr<ShoppingList> findList(string listName) const{
        for (auto const &s: shoppingLists)
            if (s->getListName() == listName)
                return s;
        cout << "List " << listName << "not found." << endl;
        return nullptr;
    }

    void addProductToList(string listName, Product* product, int quantity) const{
        shared_ptr<ShoppingList> s = findList(listName);
        if (s != nullptr){
                s->addProduct(product, quantity);
                cout << "Product " << product->getName() << " added to list " << listName << "." << endl;
            }
    }

    void removeProductFromList(string listName, Product* product, int quantity) const {
        shared_ptr<ShoppingList> s = findList(listName);
        if(s != nullptr) {
            //if(s->findProduct(product->getName()) != nullptr) {
                s->removeProduct(product, quantity);
                cout << "Product " << product->getName() << " removed from list " << listName << endl;
            //}
        }
    }

    void addList(shared_ptr<ShoppingList>& list){
        bool found = false;
        for (auto const &s : shoppingLists) {
            if (list->getListName() == s->getListName()) {
                found = true;
            }
        }
        if (found)
            cout << list->getListName() << " already exists." << endl;
        else {
            shoppingLists.push_back(list);
            cout << "List " << list->getListName() << " added." << endl;
        }
    }

private:

    string name;
    list<shared_ptr<ShoppingList>> shoppingLists;

};


#endif //SHOPPINGLIST_CLIENT_H
