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
    /*int numList = 0;
    for(auto const& i : c.getShoppingLists()){
        numList++;
    }*/
    ASSERT_EQ(c.getShoppingLists().size(), 1);
    c.addList(make_shared<ShoppingList>("testList2"));
    c.addList(make_shared<ShoppingList>("testList3"));
    c.addList(make_shared<ShoppingList>("testList3"));
    /*numList = 0;
    for(auto const& i : c.getShoppingLists()){
        numList++;
    }*/
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
    /*int numList = 0;
    for(auto const& i : c.getShoppingLists()){
        numList++;
    }*/
    ASSERT_EQ(c.getShoppingLists().size(), 4);
    c.removeList(c.findList("testList2"));
    c.removeList(c.findList("testList3"));
    /*numList = 0;
    for(auto const& i : c.getShoppingLists()){
        numList++;
    }*/
    ASSERT_EQ(c.getShoppingLists().size(), 2);
}

TEST_F(ClientViewTestFixture, AddProductToListTest) {
    ASSERT_EQ(c.findList("testList")->getListProduct().begin()->getName(), "testProduct");
    c.addProductToList("testList", Product("testProduct2", "testCategory",1));
    c.addProductToList("testList", Product("testProduct3", "testCategory",2));
    /*int numProducts = 0;
    for(auto const& i : c.findList("testList")->getListProduct())
        numProducts++;*/
    ASSERT_EQ(c.findList("testList")->getListProduct().size(), 3);
}

TEST_F(ClientViewTestFixture, RemoveProductFromListTest){
    c.removeProductFromList("testList", Product("testProduct", "testCategory",1));
    ASSERT_EQ(c.findList("testList")->getListProduct().empty(), true);
    c.addProductToList("testList", Product("testProduct2", "testCategory",1));
    c.addProductToList("testList", Product("testProduct3", "testCategory",2));
    c.removeProductFromList("testList", Product("testProduct2", "testCategory",1));
    /*int numProducts = 0;
    for(auto const& i : c.findList("testList")->getListProduct())
        numProducts++;*/
    ASSERT_EQ(c.findList("testList")->getListProduct().size(), 1);
}
