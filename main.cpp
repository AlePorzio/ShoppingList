#include <iostream>
#include <memory>
#include "Product.h"
#include "Client.h"

int main() {
    Product milk("Skimmed Milk", "Dairy", 1.3);
    Product meat ("Beef", "Meat", 3.8);
    Product tomato ("Round Tomatoes", "Vegetables", 2,0);
    Product cheese("Parmesan", "Dairy", 2,6);

    unique_ptr<Client> client(new Client("Ale"));
    shared_ptr<ShoppingList> shoppingList (new ShoppingList("ListaSpesa"));

    client->addList(shoppingList);
    client->addProductToList("ListaSpesa",&milk, 3);
    client->removeProductFromList("ListaSpesa",&milk, 3);
    client->addProductToList("ListaSpesa",&meat, 3);
}
