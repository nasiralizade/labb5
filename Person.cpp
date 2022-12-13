//
// Created by Nasir Alizade on 2022-12-11.
//

#include "Person.h"

Person::Person(std::string name, double age) : name(name), age(age) {}

Person::Person(const Person &person) : name(person.name), age(person.age) {}

bool operator==(const Person &lhs, const Person &rhs) {
    return lhs.name == rhs.name;
}














