//
// Created by Alessandro on 15/06/2022.
//

#ifndef SHOPPINGLIST_PRODUCT_H
#define SHOPPINGLIST_PRODUCT_H

#include <string>

using namespace std;

class Product {

public:

    Product(string n, float p, int s): name{std::move(n)}, price{p}/*, inStock{s}*/{};

    float getPrice() const {
        return price;
    }

    void setPrice(float p) {
        price = p;
    }

    /*
    int getInStock() const {
        return inStock;
    }

    void setInStock(int i) {
        inStock = i;
    }

    bool checkAvailable(int demand) const{
        if (inStock < demand)
            return false;
        return true;
    }
    */
private:

    string name;
    float price;

};


#endif //SHOPPINGLIST_PRODUCT_H
