//
// Created by Alessandro on 15/06/2022.
//

#ifndef SHOPPINGLIST_PRODUCT_H
#define SHOPPINGLIST_PRODUCT_H

#include <string>

using namespace std;

class Product {

public:

    Product(string n, string c, float p, bool a = true): name{move(n)}, category(move(c)), price{p}, available{a}{};

    float getPrice() const {
        return price;
    }

    void setPrice(float p) {
        price = p;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &n) {
        Product::name = n;
    }

    bool getAvailable() const {
        return available;
    }

    void setAvailable(int i) {
        available = i;
    }

private:

    string name;
    string category;
    float price;
    bool available;
};


#endif //SHOPPINGLIST_PRODUCT_H
