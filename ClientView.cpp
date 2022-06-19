//
// Created by Alessandro on 15/06/2022.
//

#include "ClientView.h"

shared_ptr<ShoppingList> ClientView::findList(const string & listName) const {
    for (auto const &s: shoppingLists)
        if (s->getListName() == listName)
            return s;
    return nullptr;
}

void ClientView::addProductToList(const string& listName, const Product& product) const {
        shared_ptr<ShoppingList> s = findList(listName);
        if (s != nullptr){
            s->addProduct(product);
        }
}

void ClientView::removeProductFromList(const string& listName, const Product& product) const {
    shared_ptr<ShoppingList> s = findList(listName);
    if(s != nullptr) {
        s->removeProduct(product);
    }
}

void ClientView::addList(const shared_ptr<ShoppingList> & list) {
    bool found = false;
    for (auto const &s : shoppingLists) {
        if (list->getListName() == s->getListName()) {
            found = true;
        }
    }
    if(!found) {
        shoppingLists.push_back(list);
        list->registerObserver(this);
    }
}

void ClientView::removeList(const shared_ptr<ShoppingList> & list) {
    for(auto s = shoppingLists.begin(); s != shoppingLists.end(); s++){
        if (list->getListName() == s->get()->getListName()) {
            list->removeObserver(this);
            s = shoppingLists.erase(s);
        }
    }
}

void ClientView::buyList(const string & listName) const {
    shared_ptr<ShoppingList> s = findList(listName);
    if (s != nullptr)
        s->buyProducts();
}

const list<shared_ptr<ShoppingList>> &ClientView::getShoppingLists() const {
    return shoppingLists;
}

const string &ClientView::getName() const {
    return name;
}
