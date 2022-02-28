#include <iostream>
#include "bubble_sort/bubble.hpp"
#include <vector>

template<typename T>
std::vector<T> generateVector(std::vector<T>& vec, int minValue = 0, int maxValue = 100, int size = 1000) {
    return vec;
}

template<typename T>
void printVector(std::vector<T>& vec) {
    for (const auto & ele : vec) {
        std::cout << ele << " ";
    }
    std::cout << '\n';
}

void separator(std::string name) {
    std::cout << "-------------------- " << name << " -------------------------\n";
}

void separator() {
    std::cout << "----------------------------------------------------------\n\n";
}

int main() {
    separator("bubble sort");
    std::vector<int> testVector{ 2, 4, 11, 4, 6, 9, 1, 112, 44, 66, 999, 7 };
    printVector(testVector);
    testVector = generateVector(testVector, 0, 100, 1000);
    bubble(testVector);
    printVector(testVector);
    separator();
    return 0;
}