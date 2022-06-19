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
    shared_ptr<ShoppingList> s{};
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
    int numProducts = 0;
    for(auto const& i : s->getListProduct())
        numProducts++;
    ASSERT_EQ(numProducts, 2);
    s->removeProduct(Product("testProduct2", "testCategory", 2));
    s->removeProduct(Product("testProduct3", "testCategory", 1));
    ASSERT_EQ(s->getListProduct().empty(), true);
}

TEST_F(ShoppingListTestFixture, BuyProductsTest){
    s->addProduct(Product("testProduct1", "testCategory", 1));
    s->addProduct(Product("testProduct2", "testCategory", 3));
    s->addProduct(Product("testProduct2", "testCategory", 2, true));
    s->buyProducts();
    for(auto const & p : s->getListProduct()){
        ASSERT_EQ(p.isBought(), true);
    }
}

TEST_F(ShoppingListTestFixture, RegisterObserverTest){
    ASSERT_EQ(s->getObservers().empty(), true);
    ClientView clientView1, clientView2;
    clientView1.addList(s);
    clientView2.addList(s);
    int numObservers = 0;
    for(auto const & i : s->getObservers())
        numObservers++;
    ASSERT_EQ(numObservers, 2);
}

TEST_F(ShoppingListTestFixture, RemoveObserverTest){
    ClientView clientView1, clientView2;
    clientView1.addList(s);
    clientView2.addList(s);
    clientView1.removeList(s);
    int numObservers = 0;
    for(auto const & i : s->getObservers())
        numObservers++;
    ASSERT_EQ(numObservers, 1);
    clientView2.removeList(s);
    ASSERT_EQ(s->getObservers().empty(), true);
}

TEST_F(ShoppingListTestFixture, NotifyObserverTest){
    ClientView clientView1, clientView2;
    clientView1.addList(s);
    clientView2.addList(s);
    s->notifyObserver();
}