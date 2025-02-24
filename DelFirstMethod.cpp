#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class DelFirstMethod {
private:
    unsigned long long numberOfComparisons = 0;
    unsigned long long numberOfTransfers = 0;
    vector<char> originalArray = {};
    vector<char> modifiedArray = {};
    char target = '_';
    chrono::milliseconds duration = chrono::milliseconds(0);

public:
    void run() {
        unsigned long long size = originalArray.size();
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < size; ++i) {
            ++numberOfComparisons;
            if (modifiedArray[i] == target) {
                for (int j = i; j < size - 1; ++j) {
                    ++numberOfTransfers;
                    modifiedArray[j] = modifiedArray[j + 1];
                }
                --size;
                modifiedArray.pop_back();
                return;
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

    void printDuration() const {
        cout << "Duration: " << duration.count() << "ms\n";
    }

    void printArray() const {
        for (char i: modifiedArray) {
            cout << i << ", ";
        }
        cout << '\n';
    }

    void setArray(const vector<char> &array) {
        originalArray = array;
        modifiedArray = array;
    }

    void printReport() const {
        int exampleSizeM;
        if (modifiedArray.size() < 10) {
            exampleSizeM = modifiedArray.size();
        } else {
            exampleSizeM = 10;
        }

        int exampleSizeO;
        if (originalArray.size() < 10) {
            exampleSizeO = originalArray.size();
        } else {
            exampleSizeO = 10;
        }

        cout << "Original Array: ";
        for (int i = 0; i < exampleSizeO; ++i) {
            cout << originalArray[i] << ", ";
        }

        cout << "\nModified Array: ";
        for (int i = 0; i < exampleSizeM; ++i) {
            cout << modifiedArray[i] << ", ";
        }
        cout << "\n";
        printRateOfDifficulty();
        printDuration();
    }
};
