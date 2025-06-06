// ---------------------- person.h ----------------------
#ifndef PERSON_H
#define PERSON_H

#include <vector>
#include <string>

class Person {
protected:
    std::string name;
    std::string email;

public:
    Person(std::string n = "", std::string e = "");
    virtual void displayMenu(std::vector<class Song>& globalSongs) = 0; // pass globalSongs
    virtual std::string getRole() = 0;
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
};

#endif