#include <iostream>
#include "DelFirstMethod.cpp"
#include "DelOtherMethod.cpp"
#include "ArrayFactory.cpp"

using namespace std;

int main() {
    auto* arrayFactory = new ArrayFactory();

    auto* del_first_method = new DelFirstMethod();
    del_first_method->setArray(arrayFactory->generateArray(900000000, ArrayFactory::Case::AVERAGE));
    del_first_method->run();
    del_first_method->printReport();

    std::cout << std::endl;
    auto* del_other_method = new DelOtherMethod();
    del_other_method->setArray(arrayFactory->generateArray(90000000, ArrayFactory::Case::AVERAGE));
    del_other_method->run();
    del_other_method->printReport();
}
