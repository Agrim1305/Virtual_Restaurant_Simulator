#ifndef PERSON_H
#define PERSON_H

#include <string>

// Declaration of the Person class, which serves as a base class for other classes
class Person {
protected:
    std::string name; // Name of the person
    int id; // Unique ID for the person

public:
// Initialize the Person's name and ID
    Person(const std::string& name, int id);
    virtual ~Person() {}

// Method to return the name and ID 
    std::string get_name() const;
    int get_id() const;
};

#endif
