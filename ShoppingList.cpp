//
// Created by Alessandro on 15/06/2022.
//

#include "ShoppingList.h"

void ShoppingList::addProduct(Product *p, int quantity) {
    auto product = products.find(p);
    if (products.find(p) == products.end())
        products.emplace(p, quantity);
    else{
        product->second += quantity;
    }
    notifyObserver();
}

void ShoppingList::removeProduct(Product* p, int quantity){
    auto product = products.find(p);
    if (products.find(p) != products.end()) {
        product->second -= quantity;
        if (product->second <= 0)
            products.erase(p);
    }
    notifyObserver();
}