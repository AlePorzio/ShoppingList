//
// Created by Alessandro on 15/06/2022.
//

#ifndef SHOPPINGLIST_SHOPPINGLIST_H
#define SHOPPINGLIST_SHOPPINGLIST_H

#include <list>
#include <memory>
#include <string>
#include <map>
#include "Subject.h"
#include "Observer.h"
#include "Product.h"
using namespace std;

class ShoppingList : public Subject {

private:

    string listName;
    list<unique_ptr<Observer>> observers;
    map<unique_ptr<Product>, int> products;

public:

    const string &getListName() const {
        return listName;
    }

    void setListName(const string& list) {
        listName = list;
    }

    virtual void addProduct(unique_ptr<Product> p, int quantity){
        products.emplace(move(p), quantity);
        notifyObserver();
    }

    virtual void changeQuantity(unique_ptr<Product> p, int quantity){
        auto it = products.find(p);
        it->second = quantity;
        if (quantity <= 0)
            products.erase(p);
    }

    virtual void removeProduct(unique_ptr<Product> p, int quantity){
        products.erase(p);
        notifyObserver();
    }

    void notifyObserver() override{
        for(auto const& o : observers)
            o->update(listName);
    }

    const unique_ptr<Product>& checkProduct(const string& name){
        for(auto const& p : products)
            if (p.first->getName() == name){
                return std::move(p.first);
            }
        return nullptr;
    }
};


#endif //SHOPPINGLIST_SHOPPINGLIST_H
