#include <iostream>
#include "bubble_sort/bubble.hpp"
#include "selection_sort/selection.hpp"
#include "insert_sort/insert.hpp"
#include "bucket_sort/bucket.hpp"
#include "radix_sort/radix.hpp"
#include "merge_sort/merge.hpp"
#include "quick_sort/quick.hpp"
#include <vector>
#include <random>

template<typename T>
std::vector<T> generateVector(std::vector<T>& vec, int minValue = -100, int maxValue = 100, int size = 12) {
    vec.clear();
    vec.reserve(size);
    std::random_device seed;
    std::mt19937 randomNumber{seed()}; 
    std::uniform_int_distribution<int> range(minValue, maxValue);
    for (size_t i = 0; i < vec.capacity(); i++) {
        vec.push_back(range(randomNumber));
    }
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
    {
        separator("bubble sort");
        std::vector<int> testVector;
        generateVector(testVector);
        printVector(testVector);
        bubble(testVector);
        printVector(testVector);
        separator();
    }

    {
        separator("selection sort first");
        std::vector<int> testVector;
        generateVector(testVector);
        printVector(testVector);
        selectionFirst(testVector);
        printVector(testVector);
        separator();
    }

    {
        separator("selection sort second");
        std::vector<int> testVector;
        generateVector(testVector);
        printVector(testVector);
        selectionSecond(testVector);
        printVector(testVector);
        separator();
    }

    {
        separator("insert sort first");
        std::vector<int> testVector;
        generateVector(testVector);
        printVector(testVector);
        insertFirst(testVector);
        printVector(testVector);
        separator();
    }

    {
        separator("insert sort second");
        std::vector<int> testVector;
        generateVector(testVector);
        printVector(testVector);
        insertSecond(testVector);
        printVector(testVector);
        separator();
    }

    {
        separator("bucket sort first");
        std::vector<int> testVector;
        generateVector(testVector);
        printVector(testVector);
        bucketFirst(testVector);
        printVector(testVector);
        separator();
    }

    {
        separator("bucket sort second");
        std::vector<int> testVector;
        generateVector(testVector);
        printVector(testVector);
        bucketSecond(testVector);
        printVector(testVector);
        separator();
    }

    {
        separator("radix sort first");
        std::vector<int> testVector;
        generateVector(testVector, 0, 1000, 10);
        printVector(testVector);
        radixFirst(testVector);
        printVector(testVector);
        separator();
    }

    {
        separator("merge sort first");
        std::vector<int> testVector;
        generateVector(testVector);
        printVector(testVector);
        mergeFirst(testVector, 0, static_cast<int>(testVector.size() - 1));
        printVector(testVector);
        separator();
    }

    {
        separator("merge sort second");
        std::vector<int> testVector;
        generateVector(testVector);
        printVector(testVector);
        mergeSecond(testVector.begin(), testVector.end() - 1);
        printVector(testVector);
        separator();
    }

    {
        separator("quick sort first");
        std::vector<int> testVector;
        generateVector(testVector, 0, 19, 10);
        printVector(testVector);
        callQuickFirst(testVector);
        printVector(testVector);
        separator();
    }

    // {
    //     separator("quick sort second");
    //     std::vector<int> testVector;
    //     generateVector(testVector);
    //     printVector(testVector);
    //     callQuickSecond(testVector);
    //     printVector(testVector);
    //     separator();
    // }

    return 0;
}