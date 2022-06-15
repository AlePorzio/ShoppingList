//
// Created by Alessandro on 15/06/2022.
//

#ifndef SHOPPINGLIST_SHOPPINGLIST_H
#define SHOPPINGLIST_SHOPPINGLIST_H

#include <list>
#include <memory>
#include <string>
#include <map>
#include <iostream>
#include "Subject.h"
#include "Observer.h"
#include "Product.h"
using namespace std;

class ShoppingList : public Subject {

private:

    string listName;
    list<Observer*> observers;
    map<unique_ptr<Product>, int> products;

public:

    void notifyObserver() override{
        for(auto const& o : observers)
            o->update(listName);
    }

    void registerObserver(Observer* o) override{
        observers.push_back(o);
    }

    void removeObserver(Observer* o) override{
        observers.remove(o);
    }

    const string &getListName() const {
        return listName;
    }

    void setListName(const string& list) {
        listName = list;
    }

    const map<unique_ptr<Product>, int> &getProducts() const {
        return products;
    }

    virtual void addProduct(unique_ptr<Product> p, int quantity){
        auto product = products.find(p);
        if (products.find(p) == products.end())
            products.emplace(move(p), quantity);
        else{
            product->second += quantity;
        }
        notifyObserver();
    }

    /*virtual void changeQuantity(unique_ptr<Product> p, int quantity){
        auto product = products.find(p);
        if (products.find(p) != products.end()) {
            product->second -= quantity;
            if (quantity <= 0)
                products.erase(p);
        }
        notifyObserver();
    }*/

    virtual void removeProduct(unique_ptr<Product> p, int quantity){
        auto product = products.find(p);
        if (products.find(p) != products.end()) {
            product->second -= quantity;
            if (quantity <= 0)
                products.erase(p);
        }
        notifyObserver();
    }

    /*const unique_ptr<Product>& findProduct(const string& name){
        for(auto const& p : products)
            if (p.first->getName() == name){
                return std::move(p.first);
            }
        return nullptr;
    }*/
};


#endif //SHOPPINGLIST_SHOPPINGLIST_H
