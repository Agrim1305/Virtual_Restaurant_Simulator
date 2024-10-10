#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include <stdexcept>

class Ingredient {
private:
    std::string name;
    int quantity;

public:
    // Default constructor
    Ingredient() : name("Unknown"), quantity(0) {}  // Initialize with default values

    // Constructor with name and quantity
    Ingredient(const std::string& name, int quantity);

    // Getters
    std::string get_name() const;
    int get_quantity() const;

    // Setters
    void set_quantity(int quantity);
    
    // Use ingredient (reduce the quantity)
    void use(int amount);

    // Restock ingredient (increase the quantity)
    void restock(int amount);
};

#endif
