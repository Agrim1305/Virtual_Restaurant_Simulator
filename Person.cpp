#include "Person.h"

// Initializes the Person's name and ID
Person::Person(const std::string& name, int id) : name(name), id(id) {}

// Method to return the Person's name
std::string Person::get_name() const {
    return name;
}
//  Method to return the Person's ID
int Person::get_id() const {
    return id;
}
