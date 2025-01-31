#include <iostream>
#include <cmath>
#include "Laba2sem4/Laba2sem4.h"

void Multipliers(int n, MyStack<int>& stack) {
    int temp_n = n;
    int* arr = new int[30];
    int count = 0;
    while (n % 2 == 0) {
        stack.push(2);
        arr[count++] = 2;
        n = n / 2;

    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            stack.push(i);
            arr[count++] = i;
            n = n / i;
        }
    }
    if (n > 2) {
        stack.push(n);
        arr[count++] = n;
    }
    std::cout << temp_n << "=";
    while (!stack.empty()) {
        std::cout << stack.top_inf();
        stack.pop();
        if (!stack.empty()) {
            std::cout << " * ";
        }
    }
    std::cout << std::endl;

    for (int i = count - 1; i > -1; i--) {
        stack.push(arr[i]);
    }
    std::cout << temp_n << "=";
    while (!stack.empty()) {
        std::cout << stack.top_inf();
        stack.pop();
        if (!stack.empty()) {
            std::cout << " * ";
        }
    }
    std::cout << std::endl;


    delete[] arr;
}

int main() {
    setlocale(LC_ALL, "Russian");
    MyStack<int> stack;
    stack.push(5);
    stack.push(19);
    MyStack<int> stack1;
    stack1 = stack;
    MyStack<int> stack2{ stack1 };
    std::cout << stack.top_inf() << " ";
    std::cout << stack1.top_inf() << " ";
    std::cout << stack2.top_inf() << std::endl;
    stack.pop(); stack1.pop(); stack2.pop();
    std::cout << stack.top_inf() << " ";
    std::cout << stack1.top_inf() << " ";
    std::cout << stack2.top_inf() << std::endl;

    int value;
    std::cout << "Введите целое число:" << std::endl;
    std::cin >> value;
 
    MyStack<int> stack_;
    Multipliers(value, stack_);
    return 0;

}
