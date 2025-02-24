#include <vector>
#include <random>

using namespace std;

class ArrayFactory {
private:
    char target = '_';
    char nonTarget = 'F';

    static bool flipCoin() {
        return rand() % 2 == 0;
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

    [[nodiscard]] vector<char> generateArray(unsigned long long size, Case _case) const {
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
};
