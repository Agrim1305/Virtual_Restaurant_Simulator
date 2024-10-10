#include "Person.h"

// Constructor
Person::Person(const std::string& name, int id)
    : name(name), id(id) {}

// Get the person's name
std::string Person::get_name() const {
    return name;
}

// Get the person's ID
int Person::get_id() const {
    return id;
}
