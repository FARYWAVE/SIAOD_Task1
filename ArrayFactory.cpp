#include <vector>
#include <random>

using namespace std;

class ArrayFactory {
private:
    char target = '_';
    char nonTarget = 'F';
    static int randInt() {
        return rand();
    }
    static bool flipCoin() {
        return rand() % 50 == 0;
    }

public:
    enum class Case {
        BEST,
        AVERAGE,
        WORST,
    };

    void setPriorities(char target, char nonTarget) {
        this->target = target;
        this->nonTarget = nonTarget;
    }

    [[nodiscard]] vector<char> generateCharArray(unsigned long long size, Case _case) const {
        vector<char> result(size);
        switch (_case) {
            case Case::BEST:
                fill(result.begin(), result.end(), nonTarget);
                break;
            case Case::AVERAGE:
                for (int i = 0; i < size; ++i) {
                    result[i] = flipCoin() ? target : nonTarget;
                }
                break;
            case Case::WORST:
                fill(result.begin(), result.end(), target);
                break;
        }
        return result;
    }
    [[nodiscard]] vector<int> generateIntArray(unsigned long long size, Case _case) const {
        vector<int> result(size);
        switch (_case) {
            case Case::BEST:
                for (int i = 0; i < size; ++i) {
                    result[i] = i + 1;
                }
            break;
            case Case::AVERAGE:
                for (int i = 0; i < size; ++i) {
                    result[i] = randInt();
                }
            break;
            case Case::WORST:
                for (int i = 0; i < size; ++i) {
                    result[i] = size - i;
                }
            break;
        }
        return result;
    }
};
