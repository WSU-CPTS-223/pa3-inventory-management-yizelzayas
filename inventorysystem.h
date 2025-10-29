#ifndef INVENTORYSYSTEM_H
#define INVENTORYSYSTEM_H
#include "product.h"
#include "linkedlist.h"
#include "hashtable.h"
#include <string>

class InventorySystem{
    private:
    HashTable<std::string, Product> productsById;
    HashTable<std::string, LinkedList<Product>> productsByCategory;
    public:
    InventorySystem(){}
    void loadData(const std::string& filename);
    void findProduct(const std::string& id);
    void listCategory(const std::string& category);
};
#endif