//
// Created by Alessandro on 19/06/2022.
//
#include "gtest/gtest.h"
#include "../ShoppingList.h"
#include "../ClientView.h"


class ShoppingListTestFixture : public ::testing::Test {

protected:

    virtual void SetUp() {
        s = make_shared<ShoppingList>("testList");
    }

    shared_ptr<ShoppingList> s;
};

TEST_F(ShoppingListTestFixture, Constructor){
    ASSERT_EQ("testList", s->getListName());
}

TEST_F(ShoppingListTestFixture, AddProductTest) {
    s->addProduct(Product("testProduct", "testCategory", 1));
    ASSERT_EQ(s->getListProduct().begin()->getName(), "testProduct");
    s->addProduct(Product("testProduct", "testCategory", 1));
    ASSERT_EQ(s->getListProduct().begin()->getQuantity(), 2);
    s->addProduct(Product("testProduct2", "testCategory2", 2));
    s->addProduct(Product("testProduct3", "testCategory2", 1));
    int numProducts = 0;
    for(auto const& i : s->getListProduct())
        numProducts++;
    ASSERT_EQ(numProducts, 3);
}

TEST_F(ShoppingListTestFixture, RemoveProductTest){
    s->addProduct(Product("testProduct", "testCategory", 2));
    s->removeProduct(Product("testProduct", "testCategory", 1));
    ASSERT_EQ(s->getListProduct().begin()->getQuantity(), 1);
    s->removeProduct(Product("testProduct", "testCategory", 1));
    s->addProduct(Product("testProduct2", "testCategory2", 2));
    s->addProduct(Product("testProduct3", "testCategory2", 1));
    ASSERT_EQ(s->getListProduct().size(), 2);
    s->removeProduct(Product("testProduct2", "testCategory", 2));
    s->removeProduct(Product("testProduct3", "testCategory", 1));
    ASSERT_EQ(s->getListProduct().empty(), true);
}

TEST_F(ShoppingListTestFixture, BuyProductTest){
    s->addProduct(Product("testProduct", "testCategory", 1));
    ASSERT_EQ(s->getListProduct().begin()->isBought(), false);
    s->buyProduct(Product("testProduct", "testCategory", 1));
    ASSERT_EQ(s->getListProduct().begin()->isBought(), true);
}

TEST_F(ShoppingListTestFixture, SetProductToNotBoughtTest){
    s->addProduct(Product("testProduct", "testCategory", 1, true));
    ASSERT_EQ(s->getListProduct().begin()->isBought(), true);
    s->setProductToNotBought(Product("testProduct", "testCategory", 1));
    ASSERT_EQ(s->getListProduct().begin()->isBought(), false);
}

TEST_F(ShoppingListTestFixture, PrintProductsCategoryOrderTest){
    s->addProduct(Product("testProduct", "testCategory", 1));
    s->addProduct(Product("testProduct1", "testCategory1", 1));
    s->addProduct(Product("testProduct2", "testCategory", 1));
    s->addProduct(Product("testProduct3", "testCategory1", 1));
    list<string> categories;
    for (auto const & p : s->getListProduct())
        categories.push_back(p.getCategory());
    categories.sort();
    categories.unique();
    ASSERT_EQ(categories.size(), 2);
}
