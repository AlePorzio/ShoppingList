//
// Created by Alessandro on 15/06/2022.
//

#ifndef SHOPPINGLIST_SHOPPINGLIST_H
#define SHOPPINGLIST_SHOPPINGLIST_H

#include <list>
#include <memory>
#include <string>
#include "Subject.h"
#include "Observer.h"
#include "Product.h"
using namespace std;

class ShoppingList : public Subject {

private:

    string listName;
    list<unique_ptr<Observer>> observers;
    list<unique_ptr<Product>> products;

public:

    const string &getListName() const {
        return listName;
    }

    void setListName(const string& list) {
        listName = list;
    }

    virtual void addProduct(unique_ptr<Product> p, int quantity){
        products.push_back(move(p));
        notifyObserver();
    }

    virtual void removeProduct(unique_ptr<Product> p, int quantity){
        products.remove(p);
        notifyObserver();
    }

    void notifyObserver() override{
        for(auto const& o : observers)
            o->update(listName);
    }

};


#endif //SHOPPINGLIST_SHOPPINGLIST_H
