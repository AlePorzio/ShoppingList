//
// Created by Alessandro on 15/06/2022.
//

#ifndef SHOPPINGLIST_SHOPPINGLIST_H
#define SHOPPINGLIST_SHOPPINGLIST_H

#include <list>
#include <memory>
#include <string>
#include <iostream>
#include <utility>
#include "Subject.h"
#include "Observer.h"
#include "Product.h"
using namespace std;

class ShoppingList : public Subject {

private:

    string listName;
    list<Observer*> observers;
    list<Product> products;
    string lastOperation;

public:

    explicit ShoppingList(string l):listName(std::move(l)){};

    virtual void notifyObserver() override{
        for(auto const& o : observers)
            o->update(lastOperation);
    }

    virtual void registerObserver(Observer* o) override{
        observers.push_back(o);
    }

   virtual void removeObserver(Observer* o) override{
        observers.remove(o);
    }

    const string &getListName() const {
        return listName;
    }

    const list<Observer *> &getObservers() const;

    void setListName(const string& list) {
        listName = list;
    }

    list<Product>& getListProduct(){
        return products;
    }

    virtual ~ShoppingList(){}

    void buyProducts();

    virtual void addProduct(const Product & product);

    virtual void removeProduct(const Product & product);

};


#endif //SHOPPINGLIST_SHOPPINGLIST_H
