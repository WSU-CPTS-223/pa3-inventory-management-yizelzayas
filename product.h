#ifndef Product_H
#define Product_H

#include <string>
#include <vector>
using namespace std;

class Product {
    public:
    std::string uniqu_id;
    std::string product_name;
    std::string manufacturer;
    std::vector<std::string> categories;
    double price;

    Product() : price(0.0) {}
    Product(std::string id, std::string name, std::string mfg, std::vector<std::string> cats, double p)
    : uniqu_id(id), product_name(name), manufacturer(mfg), categories(cats), price(p) {}
};
#endif