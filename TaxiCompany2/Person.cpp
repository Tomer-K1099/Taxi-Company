#include "Person.h"
#include <iostream> 

// Constructor
Person::Person(const char* name, const char* id){
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
    setId(id);
}

// Copy Constructor
Person::Person(const Person& other) : name(other.name) {
	setId(other.id);
}

// Move Constructor
Person::Person(Person&& other) : name(other.name) {
    strcpy(this->id, other.id);
    other.name = nullptr;  // Move constructor should not touch the const part
}

// Destructor
Person::~Person() {
   
}

// Copy Assignment Operator
const Person& Person::operator=(const Person& other) {
    if (this != &other) {
        name = other.name;
        strcpy(this->id, other.id);
    }
    return *this;
}

// Move Assignment Operator
const Person& Person::operator=(Person&& other) {
    if (this != &other) {
        name = other.name;
        strcpy(this->id, other.id);
        other.name = nullptr;  // Move assignment should not touch the const part
    }
    return *this;
}

// Getters
const char* Person::getName() const {
    return name;
}

const char* Person::getId() const {
    return id;
}

// Setters
bool Person::setName(const char* name) {
    strcpy(this->name ,name);  // Direct assignment
    return true;
}

bool Person::setId(const char* id) {
    strcpy(this->id, id);
    return true;
}
