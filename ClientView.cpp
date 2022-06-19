//
// Created by Alessandro on 15/06/2022.
//

#include "ClientView.h"

shared_ptr<ShoppingList> ClientView::findList(string& listName) const {
    for (auto const &s: shoppingLists)
        if (s->getListName() == listName)
            return s;
    cout << "List " << listName << "not found." << endl;
    return nullptr;
}

void ClientView::addProductToList(string listName, Product& product) const {
        shared_ptr<ShoppingList> s = findList(listName);
        if (s != nullptr){
            s->addProduct(product);
            //cout << "Product " << product.getName() << " added to list " << listName << "." << endl;
        }
}

void ClientView::removeProductFromList(string listName, Product& product) const {
    shared_ptr<ShoppingList> s = findList(listName);
    if(s != nullptr) {
        s->removeProduct(product);
        //cout << "Product " << product.getName() << " removed from list " << listName << endl;
    }
}

void ClientView::addList(shared_ptr<ShoppingList> &list) {
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

void ClientView::buyList(string listName) const {
    shared_ptr<ShoppingList> s = findList(listName);
    if (s != nullptr)
        s->buyProducts();
}