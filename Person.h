//
// Created by Nasir Alizade on 2022-12-11.
//

#ifndef LABB5_PERSON_H
#define LABB5_PERSON_H


#include <string>
#include <iostream>

class Person {
public:
    struct MyPrint{
        bool operator()(const Person& person){
            std::cout<<person.name<<", "<<person.age<<" years old\n";
        }
    };


    Person(std::string name, double age);

private:
    std::string name;
    double age;

};


#endif //LABB5_PERSON_H
