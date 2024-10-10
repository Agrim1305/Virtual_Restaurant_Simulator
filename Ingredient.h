#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include <stdexcept>

class Ingredient {
private:
    std::string name;
    int quantity;

public:
    Ingredient() : name("Unknown"), quantity(0) {}
    Ingredient(const std::string& name, int quantity);

    std::string get_name() const;
    int get_quantity() const;

    void set_quantity(int quantity);
    void use(int amount);       // Decrease quantity when used
    void restock(int amount);   // Increase quantity when restocked
};

#endif
