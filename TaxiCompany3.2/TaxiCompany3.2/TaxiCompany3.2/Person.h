#ifndef PERSON_H
#define PERSON_H
#include <string>  

const int ID_LEN = 9;

class Person {

protected:
    std::string name;
    const std::string id;

public:
    // Constructors
    Person(const std::string&  name, const std::string&  id);
    //Person(const Person& other);        // Copy Constructor
    //Person(Person&& other);            // Move Constructor
    //virtual ~Person();                // Destructor

    const Person& operator=(const Person& other);
    //const Person& operator=( Person&& other);

    // Getters
    const std::string&  getName() const;
    const std::string&  getId() const;

    // Setters
    virtual bool setName(const std::string& name);
    bool setId(const std::string&  id);
};

#endif // PERSON_H
