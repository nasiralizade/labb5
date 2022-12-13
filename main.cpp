#include <iostream>
#include <vector>
#include <numeric>
#include "Person.h"


int main() {
    std::vector<Person> peopleArr{{"Messi",   35},
                                  {"Ronaldo", 37},
                                  {"Zlatan",  41},
                                  {"Benzema", 34},
                                  {"Erikson", 19},
                                  {"Dybala",  29},
                                  {"Dybala",  20}};

    //uppgift 1
    std::vector<Person> people(peopleArr.begin(), peopleArr.end());
    MyPrint myPrint;
    std::for_each(people.begin(), people.end(), myPrint);

    //uppgift 2
    OlderThan older;
    std::cout << "\nThe first person that is over 30 years old\n";
    myPrint(*(std::find_if(people.begin(), people.end(), older)));

    // uppgift 3 
    std::cout << "\nadjacent_find\n";
    auto pair = std::adjacent_find(people.begin(), people.end());
    if (pair == people.end()) {
        std::cout << "No person were found\n";
    } else {
        std::cout << "Found person: ";
        myPrint(*pair);
    }

    //uppgift 4
    if (std::equal(people.begin(), people.end(), peopleArr.begin())) {
        std::cout << "\nThe containers are equal\n";
    } else {
        std::cout << "\nThe containers are NOT equal.\n";
    }
    //uppgift 5
    std::cout << "\n(search)\n";
    int start = 1, end = 3;
    auto subsequence = std::search(people.begin(), people.end(), people.begin() + start, people.begin() + end);
    if (subsequence == people.begin()) {
        std::cout << "No subsequence found\n";
    } else {
        for (int i = 0; i < end; ++i) {
            myPrint(*subsequence);
            subsequence++;
        }
    }

    // uppgift 6
    MyBinOp myBinOp;
    MyFunc myFunc;
    std::cout << "\nCalculate the average of the persons ages using std::accumulate and MyBinOp.\n";
    double mean = std::accumulate(people.begin(), people.end(), 0.0, myBinOp) / people.size();
    myFunc.mean = mean;
    std::cout << "Average age: " << mean << "\n";

    // uppgift 7
    std::vector<double> v2(7);
    MyUnOp myUnOp;
    PrintDoubleValue printDoubleValue;
    std::transform(people.begin(), people.end(), v2.begin(), myUnOp);
    std::cout << "\nfill in double vector 'v2' with age values from people using std::transform.\n";
    std::for_each(v2.begin(), v2.end(), printDoubleValue);
    std::cout << "\n";

    //uppgift 8
    std::cout
            << "\nReplacing all values in 'v2' with new ones using the MyFunc function operator, using the mean calculated from 5.\n";
    std::transform(v2.begin(), v2.end(), v2.begin(), myFunc);
    std::for_each(v2.begin(), v2.end(), printDoubleValue);
    std::cout << "\n";

    //uppgift 9
    std::sort(v2.begin(), v2.end());
    std::cout << "\nSorted in ascending order\n";
    std::for_each(v2.begin(), v2.end(), printDoubleValue);
    std::cout << "\n";


    return 0;
}
