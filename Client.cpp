//
// Created by Alessandro on 15/06/2022.
//

#include "Client.h"

shared_ptr<ShoppingList> Client::findList(string listName) const {
    for (auto const &s: shoppingLists)
        if (s->getListName() == listName)
            return s;
    cout << "List " << listName << "not found." << endl;
    return nullptr;
}

void Client::addProductToList(string listName, Product *product, int quantity) const {
        shared_ptr<ShoppingList> s = findList(listName);
        if (s != nullptr){
            s->addProduct(product, quantity);
            cout << "Product " << product->getName() << " added to list " << listName << "." << endl;
        }
}

void Client::removeProductFromList(string listName, Product *product, int quantity) const {
    shared_ptr<ShoppingList> s = findList(listName);
    if(s != nullptr) {
        //if(s->findProduct(product->getName()) != nullptr) {
        s->removeProduct(product, quantity);
        cout << "Product " << product->getName() << " removed from list " << listName << endl;
        //}
    }
}

void Client::addList(shared_ptr<ShoppingList> &list) {
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
        list->registerObserver(this);
        cout << "List " << list->getListName() << " added." << endl;
    }
}