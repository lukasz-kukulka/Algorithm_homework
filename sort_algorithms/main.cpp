#include <iostream>
#include "bubble_sort/bubble.hpp"
#include <vector>

template<typename T = int>
std::vector<T> generateVector(int minValue = 0, int maxValue = 100, int size = 1000) {
    std::vector<int> vec(size);
    return vec;
}

int main() {
    auto testVector = generateVector(0, 100, 1000);
    bubble(testVector);
    return 0;
}