//
// Created by Alessandro on 15/06/2022.
//

#ifndef SHOPPINGLIST_SHOPPINGLIST_H
#define SHOPPINGLIST_SHOPPINGLIST_H

#include <list>
#include <memory>
#include "Subject.h"
#include "Observer.h"
#include "Product.h"
using namespace std;

class ShoppingList : public Subject {

private:

    list<unique_ptr<Observer>> observers;
    list<unique_ptr<Product>> products;

public:

    virtual void addProduct(unique_ptr<Product> p){
        products.push_back(move(p));
        notifyObserver();
    }

    virtual void removeProduct(unique_ptr<Product> p){
        products.remove(p);
        notifyObserver();
    }

    void notifyObserver() override{
        for(auto const& o : observers)
            o->update();
    }
};


#endif //SHOPPINGLIST_SHOPPINGLIST_H
