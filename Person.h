#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
    std::string name;
    int id;

public:
    Person(const std::string& name, int id);
    virtual ~Person() {}

    std::string get_name() const;
    int get_id() const;
};

#endif
