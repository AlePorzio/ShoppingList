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

    void update(string list) override{
        cout <<  list << endl;
    }

    shared_ptr<ShoppingList> findList(string& listName) const;

    void addProductToList(string listName, Product& product) const;

    void removeProductFromList(string listName, Product& product) const;

    void addList(shared_ptr<ShoppingList>& list);

    void buyList(string listName) const;

    virtual ~ClientView(){
        for(auto const& i : shoppingLists)
            i->removeObserver(this);
    }

private:

    string name;
    list<shared_ptr<ShoppingList>> shoppingLists;

};


#endif //SHOPPINGLIST_CLIENTVIEW_H
