//
// Created by Alessandro on 15/06/2022.
//

#ifndef SHOPPINGLIST_OBSERVER_H
#define SHOPPINGLIST_OBSERVER_H

#include <string>
class ShoppingList;

class Observer {
public:

    virtual void update(std::string lastOperation) = 0;

    virtual ~Observer(){};

};


#endif //SHOPPINGLIST_OBSERVER_H
