#include <iostream>
#include <memory>
#include "Product.h"
#include "ClientView.h"

int main() {
    Product milk("Skimmed Milk", "Dairy", 1);
    Product meat ("Beef", "Meat", 3);
    Product tomato ("Round Tomatoes", "Vegetables", 2);
    Product cheese("Parmesan", "Dairy", 2);

    unique_ptr<ClientView> client(new ClientView("Ale"));
    shared_ptr<ShoppingList> shoppingList (new ShoppingList("ListaSpesa"));

    client->addList(shoppingList);
    client->addProductToList( "ListaSpesa", milk);
    client->addProductToList("ListaSpesa", meat);
    client->removeProductFromList("ListaSpesa", Product("Skimmed Milk", "Dairy", 2));

}
