#include "Person.h"
#include <iostream> 
#include <string>

// Constructor
Person::Person(const std::string& name, const std::string& id) : name(name), id(id) { 
}


 //Copy Assignment Operator
const Person& Person::operator=(const Person& other) {
    if (this != &other) {
		name = other.name;
    //    id = other.id;
    }
    return *this;
}


// Getters
const std::string& Person::getName() const {
    return name;
}

const std::string& Person::getId() const {
    return id;
}

// Setters
bool Person::setName(const std::string& name) {
    this->name = name;
    return true;
}

bool Person::setId(const std::string& id) {
    if (id.empty()) {
        return false;
    }
 // this->id = id;
    return true;
}
