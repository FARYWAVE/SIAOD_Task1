#include <iostream>
#include "AlgorithmRunner.cpp"
#include "ArrayFactory.cpp"
#include "SortRunner.cpp"

using namespace std;

int main() {
    auto* arrayFactory = new ArrayFactory();
    auto* algorithmRunner = new AlgorithmRunner();

    algorithmRunner->setArray(arrayFactory->generateCharArray(200, ArrayFactory::Case::WORST));
    algorithmRunner->runDelFirstMethod();
    algorithmRunner->printReport();
    return 0;


    int tests[] {100, 200, 500, 1000, 2000, 5000, 10000, 100000, 500000, 1000000};
    cout << "DELETION ALGORITHMS\n\n";
    cout << "FIRST ALGORITHM\n\n";
    cout << "BEST CASE\n";
    for (int n : tests) {
        algorithmRunner->setArray(
            arrayFactory->generateCharArray(n, ArrayFactory::Case::BEST));
        algorithmRunner->runDelFirstMethod();
        algorithmRunner->printReport();
        cout << "\n";
    }

    cout << "AVERAGE CASE\n";
    for (int n : tests) {
        algorithmRunner->setArray(
            arrayFactory->generateCharArray(n, ArrayFactory::Case::AVERAGE));
        algorithmRunner->runDelFirstMethod();
        algorithmRunner->printReport();
        cout << "\n";
    }

    cout << "WORST CASE\n";
    for (int n : tests) {
        algorithmRunner->setArray(
            arrayFactory->generateCharArray(n, ArrayFactory::Case::WORST));
        algorithmRunner->runDelFirstMethod();
        algorithmRunner->printReport();
        cout << "\n";
    }

    cout << "SECOND ALGORITHM\n\n";
    cout << "BEST CASE\n";
    for (int n : tests) {
        algorithmRunner->setArray(
            arrayFactory->generateCharArray(n, ArrayFactory::Case::BEST));
        algorithmRunner->runDelOtherMethod();
        algorithmRunner->printReport();
        cout << "\n";
    }

    cout << "AVERAGE CASE\n";
    for (int n : tests) {
        algorithmRunner->setArray(
            arrayFactory->generateCharArray(n, ArrayFactory::Case::AVERAGE));
        algorithmRunner->runDelOtherMethod();
        algorithmRunner->printReport();
        cout << "\n";
    }

    cout << "WORST CASE\n";
    for (int n : tests) {
        algorithmRunner->setArray(
            arrayFactory->generateCharArray(n, ArrayFactory::Case::WORST));
        algorithmRunner->runDelOtherMethod();
        algorithmRunner->printReport();
        cout << "\n";
    }

    auto* sortRunner = new SortRunner();
    cout << "SORT ALGORITHMS\n\n";
    cout << "INSERTION ALGORITHM\n\n";
    cout << "BEST CASE\n";
    for (int n : tests) {
        sortRunner->setArray(
            arrayFactory->generateIntArray(n, ArrayFactory::Case::BEST));
        sortRunner->runInsertionSort();
        sortRunner->printReport();
        cout << "\n";
    }

    cout << "AVERAGE CASE\n";
    for (int n : tests) {
        sortRunner->setArray(
            arrayFactory->generateIntArray(n, ArrayFactory::Case::AVERAGE));
        sortRunner->runInsertionSort();
        sortRunner->printReport();
        cout << "\n";
    }

    cout << "WORST CASE\n";
    for (int n : tests) {
        sortRunner->setArray(
            arrayFactory->generateIntArray(n, ArrayFactory::Case::WORST));
        sortRunner->runInsertionSort();
        sortRunner->printReport();
        cout << "\n";
    }

    cout << "SELECTION ALGORITHM\n\n";
    cout << "BEST CASE\n";
    for (int n : tests) {
        sortRunner->setArray(
            arrayFactory->generateIntArray(n, ArrayFactory::Case::BEST));
        sortRunner->runSelectionSort();
        sortRunner->printReport();
        cout << "\n";
    }

    cout << "AVERAGE CASE\n";
    for (int n : tests) {
        sortRunner->setArray(
            arrayFactory->generateIntArray(n, ArrayFactory::Case::AVERAGE));
        sortRunner->runSelectionSort();;
        sortRunner->printReport();
        cout << "\n";
    }

    cout << "WORST CASE\n";
    for (int n : tests) {
        sortRunner->setArray(
            arrayFactory->generateIntArray(n, ArrayFactory::Case::WORST));
        sortRunner->runSelectionSort();
        sortRunner->printReport();
        cout << "\n";
    }
}