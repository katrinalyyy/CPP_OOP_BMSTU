
#include <iostream>
#include <cstring>
#include "LabaSix2/term.h"
#include "LabaSix2/polynominal.h"

int main() {
    Polynomial x1, x2;
    std::cin >> x1;
    std::cin >> x2;
    Polynomial x3;
    x3 = x1 * x2;
    std::cout << "x1 * x2 = " << x3 << '\n';
    x3 = x1 + x2;
    std::cout << "x1 + x2 = " << x3 << '\n';
    Polynomial x4;
    x4 = x2;
    x4 *= x1;
    std::cout << x4 << std::endl;
    Polynomial x5;
    x5 = x2;
    x5 += x1;
    std::cout << x5 << std::endl;

    return 0;
}
