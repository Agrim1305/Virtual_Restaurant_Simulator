#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

class Ingredient {
    std::string name;
    int quantity;

public:
    Ingredient(const std::string& name, int quantity);

    std::string get_name() const;
    int get_quantity() const;
    void use(int amount);
    void restock(int amount);
};

#endif
