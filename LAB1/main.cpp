#include <iostream>
#include "mymath/mymath.h"
#include "mymath2/mymath2.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "I can multiply! See: 10+32=";
    std::cout << mymath::sum(10, 32) << std::endl;
    std::cout << "I can minus! See: 32-10=";
    std::cout << mymath2::minus(32, 10) << std::endl;

    return 0;
}
