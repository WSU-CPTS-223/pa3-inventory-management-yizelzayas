#include "inventorysystem.h"
#include <iostream>
#include <fstream>
#include <sstream>

void InventorySystem::loadData(const std::string& filename){
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "error can't open csv file! \n";
        return;
    }
    std::string line;
    getline(file, line);

    while (getline(file, line)){
        std::stringstream ss(line);
        std::string id, name, mfg, categoryStr, priceStr;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, mfg, ',');
        getline(ss, categoryStr, ',');
        getline(ss, priceStr, ',');

        std::vector<std::string> categories;
        std::stringstream catStream(categoryStr);
        std::string cat;
        while (getline(catStream, cat, '|')) {
            if (cat.empty()) cat = "NA";
            categories.push_back(cat);
        }
        double price = priceStr.empty() ? 0.0 : std::stod(priceStr);
        Product p(id, name, mfg, categories, price);

        productsById.insert(id, p);

        for (const std::string& c : categories){
            LinkedList<Product>* list = productsByCategory.find(c);
            if (list)
            list->insert(p);
            else {
                LinkedList<Product> newList;
                newList.insert(p);
                productsByCategory.insert(c, newList);
            }
        }
    }
    std::cout << "data has loaded successfully\n";
}
void InventorySystem::findProduct(const std::string& id) {
    Product* p = productsById.find(id);
    if (!p) {
        std::cout << "inventory/product not found!";
        return;
    }
    std::cout << "Product ID: " << p->uniqu_id << "\n";
    std::cout << "Name: " << p->product_name << "\n";
    std::cout << "Manufcturer: " << p->manufacturer << "\n";
    std::cout << "Price: $" << p->price << "\n";
    std::cout << "Categories: ";
    for (auto& c : p->categories)
    std::cout << c << " ";
    std::cout << "\n";
}
void InventorySystem::listCategory(const std::string& category) {
    LinkedList<Product>* list = productsByCategory.find(category);
    if (!list){
        std::cout << "invalid category\n";
        return;
    }
    auto node = list->getHead();
    while (node) {
        std::cout << node->data.uniqu_id << " - " <<node->data.product_name << "\n";
        node = node->next;
    }
}