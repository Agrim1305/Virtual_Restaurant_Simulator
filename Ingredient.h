#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include <stdexcept>

// Declaration of the Ingredient class
class Ingredient {
private:
    std::string name;  // Name of the ingredient
    int quantity;      // Quantity of the ingredient available in stock

public:
    // Constructor initializes name to "Unknown" and quantity to 0
    Ingredient() : name("Unknown"), quantity(0) {}

    // Constructor to initialize the ingredient with a specific name and quantity
    Ingredient(const std::string& name, int quantity);

    // Method to return the name of the ingredient
    std::string get_name() const;

    // Method to return the quantity of the ingredient
    int get_quantity() const;

    // Set the quantity of the ingredient
    void set_quantity(int quantity);

    // Use a certain amount of an ingredient
    void use(int amount);

    // Restock the ingredient by a certain amount
    void restock(int amount);
};

#endif
