//
// Created by Nasir Alizade on 2022-12-11.
//

#ifndef LABB5_PERSON_H
#define LABB5_PERSON_H


#include <string>
#include <iostream>

class Person {
public:


    Person();

    struct MyPrint {// print the content
        bool operator()(const Person &person) {
            std::cout << person.name << ", " << person.age << " years old\n";
        }
    };

    struct OlderThan {// predicate function
        bool operator()(const Person &person) {
            return person.age > 20;
        }
    };

    struct MyBinOp {
        double operator()(const double &number, const Person &person) {
            return number + person.age;
        }
    };

    struct MyFunc {
        double mean;

        Person operator()(Person &lhs, Person &rhs) {
            lhs.age = rhs.age - mean;
            return lhs;
        }
    };

    struct MyUnOp {
        Person operator()(const Person &person) {
            return {person.name, person.age / 2};
        };
    };
    struct ComparePerson{
        bool operator()(const Person& lhs,const Person &rhs){
            return lhs.age<rhs.age;
        }
    };


    Person(const Person &person);

    Person(std::string name, double age);

    friend bool operator==(const Person &lhs, const Person &rhs);


private:
    std::string name;
    double age;

};


#endif //LABB5_PERSON_H
