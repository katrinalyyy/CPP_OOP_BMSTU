#include "LabaEight.h"

void printVector(std::vector<float>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void printList(std::list<int>& cont, int x) {
    std::list<int>::iterator iter;
    bool contains = false;
    if (!cont.empty()) {
        for (iter = cont.begin(); iter != cont.end(); ++iter) {
            if (*iter == x) {
                contains = true;
                break;
            }
        }
        std::cout << (contains ? "Yes" : "No") << std::endl;
    }
    else {
        std::cout << "список пуст " << std::endl;
    }
}