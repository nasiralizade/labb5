//
// Created by Nasir Alizade on 2022-12-11.
//

#ifndef LABB5_PERSON_H
#define LABB5_PERSON_H


#include <string>
#include <iostream>

class Person {
public:

    friend class MyFunc;

    friend class MyPrint;

    friend class OlderThan;

    friend class MyUnOp;

    friend class MyBinOp;

    friend class PrintDoubleValue;

    Person() = delete;

    Person(const Person &person);

    Person(std::string name, double age);

    friend bool operator==(const Person &lhs, const Person &rhs);

    virtual ~Person() = default;


private:
    std::string name;
    double age;
};

class MyFunc {
public:
    double mean = 0;

    double operator()(double d) {
        return d - mean;
    }
};

class MyPrint {
public:
    bool operator()(const Person &person) {
        std::cout << person.name << ", " << person.age << " years old\n";
    }
};

class OlderThan {// predicate function
public:
    bool operator()(const Person &person) {
        return person.age > 30;
    }
};

class MyBinOp {   //binary operation
public:
    double operator()(const double &number, const Person &person) {
        return number + person.age;
    }
};

class MyUnOp { //unary operation
public:
    double operator()(const Person &person) {
        return person.age;
    };
};

class PrintDoubleValue {
public:
    void operator()(const double &value) {
        std::cout << value << " ";
    }
};


#endif //LABB5_PERSON_H
