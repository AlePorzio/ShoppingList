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

    shared_ptr<ShoppingList> findList(string& name) const{
        for (auto const &s: shoppingLists)
            if (s->getListName() == name)
                return s;
        cout << "List " << name << "not found." << endl;
        return nullptr;
    }

    void addProductToList(string& name, unique_ptr<Product> product, int quantity) const{
        shared_ptr<ShoppingList> s = findList(name);
        if (s != nullptr){
                s->addProduct(std::move(product), quantity);
                cout << "Products added to list " << name << "." << endl;
            }
    }

    void removeProductFromList(string& name, unique_ptr<Product> product, int quantity) const {
        shared_ptr<ShoppingList> s = findList(name);
        if(s != nullptr) {
            //if(s->findProduct(product->getName()) != nullptr) {
                s->removeProduct(std::move(product), quantity);
                cout << "Products removed from list " << name << endl;
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
        else
            shoppingLists.push_back(list);
    }

private:
    list<shared_ptr<ShoppingList>> shoppingLists;


};


#endif //SHOPPINGLIST_CLIENT_H
