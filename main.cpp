#include <iostream>
#include <vector>
#include "Person.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Person peopleArr[]={{"Nasir",22},
                        {"Isaac",24}};
    std::vector<Person>people(peopleArr,peopleArr+1);
    Person::MyPrint myPrint;









    return 0;
}
