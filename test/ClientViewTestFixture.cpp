//
// Created by Alessandro on 16/06/2022.
//

#include "gtest/gtest.h"
#include "../ClientView.h"

#include <memory>


class ClientViewTestFixture : public ::testing::Test {

protected:

    virtual void SetUp() {
        c.addList(std::make_shared<ShoppingList> ("testList"));
        c.addProductToList("testList", Product("testProduct", "testCategory",1));
    }

    virtual void TearDown(){
        c.removeList(c.findList("testList"));
    }

    ClientView c;
};


TEST(ClientViewTest, DefaultConstructor){
    ClientView c;
    ASSERT_EQ(c.getName(), "");
    ASSERT_EQ(c.getShoppingLists().empty(), true);
}

TEST_F(ClientViewTestFixture, AddListTest){
    ASSERT_EQ(c.getShoppingLists().size(), 1);
    c.addList(make_shared<ShoppingList>("testList2"));
    c.addList(make_shared<ShoppingList>("testList3"));
    c.addList(make_shared<ShoppingList>("testList3"));
    ASSERT_EQ(c.getShoppingLists().size(), 3);
}

TEST_F(ClientViewTestFixture, FindListTest){
    ASSERT_EQ(c.findList("testList"), *(c.getShoppingLists().begin()));
    shared_ptr<ShoppingList> list = std::make_shared<ShoppingList>("testList2");
    c.addList(list);
    ASSERT_EQ(c.findList("testList2"), list);
}

TEST_F(ClientViewTestFixture, RemoveListTest){
    c.addList(make_shared<ShoppingList>("testList1"));
    c.addList(make_shared<ShoppingList>("testList2"));
    c.addList(make_shared<ShoppingList>("testList3"));
    ASSERT_EQ(c.getShoppingLists().size(), 4);
    c.removeList(c.findList("testList2"));
    c.removeList(c.findList("testList3"));
    ASSERT_EQ(c.getShoppingLists().size(), 2);
}

TEST_F(ClientViewTestFixture, AddProductToListTest) {
    ASSERT_EQ(c.findList("testList")->getListProduct().begin()->getName(), "testProduct");
    c.addProductToList("testList", Product("testProduct2", "testCategory",1));
    c.addProductToList("testList", Product("testProduct3", "testCategory",2));
    ASSERT_EQ(c.findList("testList")->getListProduct().size(), 3);
}

TEST_F(ClientViewTestFixture, RemoveProductFromListTest){
    c.removeProductFromList("testList", Product("testProduct", "testCategory",1));
    ASSERT_EQ(c.findList("testList")->getListProduct().empty(), true);
    c.addProductToList("testList", Product("testProduct2", "testCategory",1));
    c.addProductToList("testList", Product("testProduct3", "testCategory",2));
    c.removeProductFromList("testList", Product("testProduct2", "testCategory",1));
    ASSERT_EQ(c.findList("testList")->getListProduct().size(), 1);
}

TEST_F(ClientViewTestFixture, BuyProductTest){
    ASSERT_EQ(c.findList("testList")->getListProduct().begin()->isBought(), false);
    c.buyProduct("testList", Product("testProduct", "testCategory",1));
    ASSERT_EQ(c.findList("testList")->getListProduct().begin()->isBought(), true);
}

TEST_F(ClientViewTestFixture, SetProductToNotBoughtTest){
    shared_ptr<ShoppingList> testList = c.findList("testList");
    ASSERT_EQ(testList->getListProduct().begin()->isBought(), false);
    c.buyProduct("testList", Product("testProduct", "testCategory", 1));
    ASSERT_EQ(testList->getListProduct().begin()->isBought(), true);
    c.setProductToNotBought("testList", Product("testProduct", "testCategory", 1));
    ASSERT_EQ(testList->getListProduct().begin()->isBought(), false);
}

TEST_F(ClientViewTestFixture, GetNumberOfProductsInList){
    ASSERT_EQ(c.getNumOfProductsInList("testList"), 1);
    c.addProductToList("testList", Product("testProduct1", "testCategory1",3));
    ASSERT_EQ(c.getNumOfProductsInList("testList"), 2);
    ASSERT_EQ(c.getNumOfProductsInList("nonexistentList"), 0);
}

TEST_F(ClientViewTestFixture, GetNumberOfProductsToBuyInList){
    ASSERT_EQ(c.getNumOfProductsInListToBuy("testList"), 1);
    c.addProductToList("testList", Product("testProduct1", "testCategory1",3));
    ASSERT_EQ(c.getNumOfProductsInListToBuy("testList"), 2);
    c.buyProduct("testList", Product("testProduct", "testCategory",1));
    ASSERT_EQ(c.getNumOfProductsInListToBuy("testList"), 1);
    c.setProductToNotBought("testList", Product("testProduct", "testCategory",1));
    ASSERT_EQ(c.getNumOfProductsInListToBuy("testList"), 2);
}