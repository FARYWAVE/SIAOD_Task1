#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class SortRunner {
    unsigned long long numberOfComparisons = 0;
    unsigned long long numberOfTransfers = 0;
    vector<int> originalArray = {};
    vector<int> modifiedArray = {};
    char target = '_';
    chrono::milliseconds duration = chrono::milliseconds(0);

public:
    void runInsertionSort() {
        numberOfTransfers = 0;
        numberOfComparisons = 0;
        int size = modifiedArray.size();
        auto start = chrono::high_resolution_clock::now();
        for (int i = 1; i < size; ++i) {
            int key = modifiedArray[i];
            int j = i - 1;
            while (j >= 0 && modifiedArray[j] > key) {
                ++numberOfComparisons;
                modifiedArray[j + 1] = modifiedArray[j]; // Shift right
                ++numberOfTransfers;
                --j;
            }
            modifiedArray[j + 1] = key;
            ++numberOfTransfers;
        }
        auto end = std::chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    }
    void runSelectionSort() {
        numberOfTransfers = 0;
        numberOfComparisons = 0;
        int size = modifiedArray.size();
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < size - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < size; ++j) {
                ++numberOfComparisons;
                if (modifiedArray[j] < modifiedArray[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                swap(modifiedArray[i], modifiedArray[minIndex]);
                numberOfTransfers += 3; // Swap counts as 3 transfers
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    }

    void printRateOfDifficulty() const {
        cout << "C: " << numberOfComparisons << '\n';
        cout << "M: " << numberOfTransfers << '\n';
        cout << "T: " << numberOfComparisons + numberOfTransfers << '\n';
    }

    void setTarget(char target) {
        this->target = target;
    }

    void printArray() {
        for (char i: modifiedArray) {
            cout << i << ", ";
        }
        cout << '\n';
    }

    void printDuration() const {
        cout << "Duration: " << duration.count() << "ms\n";
    }

    void setArray(const vector<int> &array) {
        originalArray = array;
        modifiedArray = array;
    }
    void printReport() const {
        int exampleSize;
        if (modifiedArray.size() < 10) {
            exampleSize = modifiedArray.size();
        } else {
            exampleSize = 10;
        }
        cout << "Original Array: ";
        for (int i = 0; i < exampleSize; ++i) {
            cout << originalArray[i] << ", ";
        }

        cout << "\nModified Array: ";
        for (int i = 0; i < exampleSize; ++i) {
            cout << modifiedArray[i] << ", ";
        }
        cout << "\nn: " << originalArray.size() << "\n";
        printDuration();
        printRateOfDifficulty();
    }
};
