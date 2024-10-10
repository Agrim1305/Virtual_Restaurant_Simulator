#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
    std::string name;
    int id;

public:
    // Constructor
    Person(const std::string& name, int id);

    // Getter for name
    std::string get_name() const;

    // Getter for ID
    int get_id() const;
};

#endif
