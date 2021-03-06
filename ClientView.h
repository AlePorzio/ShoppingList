//
// Created by Alessandro on 15/06/2022.
//

#ifndef SHOPPINGLIST_CLIENTVIEW_H
#define SHOPPINGLIST_CLIENTVIEW_H

#include <iostream>
#include "Subject.h"
#include "Observer.h"
#include "ShoppingList.h"

using namespace std;

class ClientView : public Observer{

public:

    explicit ClientView(string n = ""): name(move(n)){
        shoppingLists = {};
    };

    void update(string lastChanges) override{
        cout <<  lastChanges << endl;
    }

    const string &getName() const;

    shared_ptr<ShoppingList> findList(const string & listName) const;

    void addProductToList(const string & listName, const Product& product) const;

    void removeProductFromList(const string & listName, const Product& product) const;

    void addList(const shared_ptr<ShoppingList>& list);

    void removeList(const shared_ptr<ShoppingList> & list);

    const list<shared_ptr<ShoppingList>> &getShoppingLists() const;

    void buyProduct(const string & listName, const Product& product) const;

    void setProductToNotBought(const string & listName, const Product& product) const;

    void printProductsInList(const string & listName) const{
        auto list = findList(listName);
        if(list != nullptr)
            list->printProducts();
    }

    void printProductsToBuyInList(const string & listName) const{
        auto list = findList(listName);
        if(list != nullptr)
            list->printProductsToBuy();
    }

    int getNumOfProductsInList(const string & listName) const{
        auto list = findList(listName);
        if(list != nullptr)
            return list->getNumberOfProducts();
        else
            return 0;
    }

    int getNumOfProductsInListToBuy(const string & listName) const{
        auto list = findList(listName);
        if(list != nullptr)
            return list->getNumberOfProductsToBuy();
        else
            return 0;
    }

    virtual ~ClientView(){
        for(auto const& i : shoppingLists)
            i->removeObserver(this);
    }

private:

    string name;
    list<shared_ptr<ShoppingList>> shoppingLists;

};


#endif //SHOPPINGLIST_CLIENTVIEW_H
