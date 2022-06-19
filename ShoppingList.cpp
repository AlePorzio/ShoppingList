//
// Created by Alessandro on 15/06/2022.
//

#include "ShoppingList.h"

void ShoppingList::addProduct(const Product& product) {
    bool found = false;
    for(auto & p : products)
        if (p.getName() == product.getName()) {
            found = true;
            p.addQuantity(product.getQuantity());
        }
    if (!found)
        products.push_back(product);
    lastOperation = to_string(product.getQuantity()) + " " + product.getName() + " added to " + getListName() + ".";
    notifyObserver();
}

void ShoppingList::removeProduct(const Product& product){
    for (auto p = products.begin(); p != products.end(); p++)
        if(p->getName() == product.getName()){
            p->removeQuantity(product.getQuantity());
        }
    lastOperation = to_string(product.getQuantity()) + product.getName() + " removed from " + getListName() + ".";
    notifyObserver();
}

void ShoppingList::buyProducts() {
    for(auto p : products){
        if(!p.isBought())
            p.setBought(true);
    }
    lastOperation = "Bought all products in " + getListName();
    notifyObserver();
}