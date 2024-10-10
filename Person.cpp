#include "Person.h"

Person::Person(const std::string& name, int id) : name(name), id(id) {}

std::string Person::get_name() const {
    return name;
}

int Person::get_id() const {
    return id;
}
