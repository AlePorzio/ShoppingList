//
// Created by Alessandro on 15/06/2022.
//

#ifndef SHOPPINGLIST_OBSERVER_H
#define SHOPPINGLIST_OBSERVER_H

class ShoppingList;

class Observer {
public:

    virtual void update(std::string listName) = 0;

};


#endif //SHOPPINGLIST_OBSERVER_H
