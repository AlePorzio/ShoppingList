//
// Created by Alessandro on 19/06/2022.
//
#include "gtest/gtest.h"
#include "../ShoppingList.h"


class ShoppingListFixture : public ::testing::Test {

protected:
    virtual void SetUp() {
        s = new ShoppingList("testList");
    }
    ShoppingList* s{};
};

TEST_F(ShoppingListFixture, Constructor){
    ASSERT_EQ("testList", s->getListName());
}

TEST_F(ShoppingListFixture, AddProductTest) {
    s->addProduct(Product("testProduct", "testCategory", 1));
    ASSERT_EQ(s->getListProduct().begin()->getName(), "testProduct");
    s->addProduct(Product("testProduct", "testCategory", 1));
    ASSERT_EQ(s->getListProduct().begin()->getQuantity(), 2);
}

TEST_F(ShoppingListFixture, RemoveProductTest){
    s->addProduct(Product("testProduct", "testCategory", 2));
    s->removeProduct(Product("testProduct", "testCategory", 1));
    ASSERT_EQ(s->getListProduct().begin()->getQuantity(), 1);
    s->removeProduct(Product("testProduct", "testCategory", 1));
    ASSERT_EQ(s->getListProduct().empty(), true);
}

TEST_F(ShoppingListFixture, BuyProductsTest){
    s->addProduct(Product("product1", "testCategory", 1));
    s->addProduct(Product("product2", "testCategory", 3));
    s->buyProducts();
    for(auto const & p : s->getListProduct()){
        ASSERT_EQ(p.isBought(), true);
    }
}