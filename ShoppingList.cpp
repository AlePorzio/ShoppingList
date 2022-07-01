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

void ShoppingList::removeProduct(const Product& product) {
    for (auto p = products.begin(); p != products.end(); p++)
        if (p->getName() == product.getName()) {
            p->removeQuantity(product.getQuantity());
            lastOperation = to_string(product.getQuantity()) + " " + product.getName() + " removed from " + getListName() + ".";
            if (p->getQuantity() <= 0) {
                p = products.erase(p);
                lastOperation = "All " + product.getName() + " removed from " + getListName() + ".";
            }
        }
    notifyObserver();
}

void ShoppingList::buyProduct(const Product &product) {
    bool changed = false;
    for(auto & p : products)
        if(p.getName() == product.getName() && p.getCategory() == product.getCategory() && !product.isBought()) {
            p.setBought(true);
            changed = true;
        }
    if(changed) {
        lastOperation = "Bought " + to_string(product.getQuantity()) + " " +  product.getName() + " in " + getListName() + ".";
        notifyObserver();
    }
}

void ShoppingList::setProductToNotBought(const Product &product)  {
    bool changed = false;
    for(auto & p : products)
        if(p.getName() == product.getName() && p.getCategory() == product.getCategory() && p.isBought()) {
            p.setBought(false);
            changed = true;
        }
    if(changed) {
        lastOperation = to_string(product.getQuantity()) + " " +  product.getName() + " set to not bought in " + getListName() + ".";
        notifyObserver();
    }
}

void ShoppingList::printProducts() {
    list<string> categories;
    for (auto const & p :products)
        categories.push_back(p.getCategory());
    categories.sort();
    categories.unique();
    for(auto const & c : categories){
        for (auto const& p : products){
            if(p.getCategory() == c)
                cout << p.getQuantity() << " " << p.getName() << endl;
        }
    }
}

void ShoppingList::printProductsToBuy() {
    list<string> categories;
    for (auto const & p :products)
        categories.push_back(p.getCategory());
    categories.sort();
    categories.unique();
    for(auto const & c : categories){
        for (auto const& p : products){
            if(p.getCategory() == c && !p.isBought())
                cout << p.getQuantity() << " " << p.getName() << endl;
        }
    }
}

int ShoppingList::getNumberOfProducts() const{
    return products.size();
}

int ShoppingList::getNumberOfProductsToBuy() const {
    int numProducts = 0;
    for(auto const & p : products){
        if(!p.isBought())
            numProducts++;
    }
    return numProducts;
}