//
// Created by Alessandro on 15/06/2022.
//

#ifndef SHOPPINGLIST_OBSERVER_H
#define SHOPPINGLIST_OBSERVER_H

#include <memory>
#include "Subject.h"

class Observer {
public:
    virtual void update(Subject& s) = 0;

};


#endif //SHOPPINGLIST_OBSERVER_H
