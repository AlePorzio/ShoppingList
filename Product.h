//
// Created by Alessandro on 15/06/2022.
//

#ifndef SHOPPINGLIST_PRODUCT_H
#define SHOPPINGLIST_PRODUCT_H

#include <string>

using namespace std;

class Product {

public:

    Product(string n, string c, int q, bool b = false): name{move(n)}, category(move(c)), quantity{q}, bought{b}{};

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int q) {
        quantity = q;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &n) {
        Product::name = n;
    }

    void addQuantity(int q){
        quantity += q;
    }

    void removeQuantity(int q){
        quantity -= q;
    }

    bool isBought() const {
        return bought;
    }

    void setBought(bool b) {
        bought = b;
    }

private:

    string name;
    string category;
    int quantity;
    bool bought;
};


#endif //SHOPPINGLIST_PRODUCT_H
