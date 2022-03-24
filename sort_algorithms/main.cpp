#include <iostream>
#include "bubble_sort/bubble.hpp"
#include <vector>

template<typename T = int>
std::vector<T> generateVector(std::vector<T>& vec, int minValue = 0, int maxValue = 100, int size = 1000) {
    return vec;
}

int main() {
    std::vector<int> testVector(10);
    testVector = generateVector(testVector, 0, 100, 1000);
    bubble(testVector);
    return 0;
}