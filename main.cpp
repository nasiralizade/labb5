#include <iostream>
#include <vector>
#include <numeric>
#include "Person.h"


int main() {
    Person peopleArr[] = {{"Messi",   35},
                          {"Ronaldo", 37},
                          {"Zlatan",  41},
                          {"Benzema", 34},
                          {"Erikson", 19},
                          {"Dybala",  29},
                          {"Messi",   35}};
    std::vector<Person> people(peopleArr, peopleArr + 6);
    Person::MyPrint myPrint;




    //uppgift 1
    std::for_each(people.begin(), people.end(), myPrint);
    //uppgift 2
    Person::OlderThan older;
    std::cout << "\nFörsta personen som är äldre än 20 år\n";
    myPrint(*(std::find_if(people.begin(), people.end(), older)));
    // uppgift 3 
    std::cout << "adjacent_find\n";
    myPrint(*std::adjacent_find(people.begin(), people.end()));  //varför den hittar ingen
    //uppgift 4
    std::cout << "\n(equal) " << (std::equal(people.begin(), people.end(), peopleArr));
    //uppgift 5
    std::cout << "\n\n(search)\n";
    myPrint(*std::search(people.begin(), people.end(), people.begin(), people.begin() + 3));
    // uppgift 6
    Person::MyBinOp myBinOp;
    Person::MyFunc myFunc;
    double mean = std::accumulate(people.begin(), people.end(), 0.0, myBinOp) / people.size();
    myFunc.mean = mean;
    std::cout << "\nAverage age: " << mean << "\n";
    // uppgift 7
    std::vector<Person> v2(6);
    Person::MyUnOp myUnOp;
    std::transform(people.begin(), people.end(), v2.begin(), myUnOp);
    std::cout << "\nhälften av alla år (trsmdform)\n";
    std::for_each(v2.begin(), v2.end(), myPrint);
    //uppgift 8
    std::transform(v2.begin(), v2.end(), people.begin(), v2.begin(), myFunc);
    std::cout << "\nage with mean removed (transform)\n";
    std::for_each(v2.begin(), v2.end(), myPrint);
    //uppgift 9
    Person::ComparePerson comparePerson;
    std::sort(v2.begin(), v2.end(), comparePerson);
    std::cout << "\nSorted in ascending order\n";
    std::for_each(v2.begin(), v2.end(), myPrint);


    return 0;
}
