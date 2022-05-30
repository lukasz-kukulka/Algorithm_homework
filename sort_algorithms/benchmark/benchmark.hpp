#include <chrono>
#include <functional>
#include <map>
#include <random>
#include <string>
#include <vector>

#include "../bubble_sort/bubble.hpp"
#include "../selection_sort/selection.hpp"
#include "../insert_sort/insert.hpp"
#include "../bucket_sort/bucket.hpp"
#include "../radix_sort/radix.hpp"
#include "../merge_sort/merge.hpp"
#include "../quick_sort/quick.hpp"

constexpr auto repetitions = 10;

std::map<std::string, std::pair<std::function<void(std::vector<int>)>, size_t>> fun {
    { "bubble sort first", std::make_pair([](std::vector<int>vec){ bubble(vec); }, 0) },
    { "bubble sort second", std::make_pair([](std::vector<int>vec){ bubbleLinear(vec); }, 0) },

    { "bucket sort first", std::make_pair([](std::vector<int>vec){ bucketFirst(vec); }, 0) },
    { "bucket sort second", std::make_pair([](std::vector<int>vec){ bucketSecond(vec); }, 0) },

    { "insert sort first", std::make_pair([](std::vector<int>vec){ insertFirst(vec); }, 0) },
    { "insert sort second", std::make_pair([](std::vector<int>vec){ insertSecond(vec); }, 0) },

    { "merge sort first", std::make_pair([](std::vector<int>vec){ mergeFirst(vec, 0, static_cast<int>(vec.size() - 1)); }, 0) },
    { "merge sort second", std::make_pair([](std::vector<int>vec){ mergeSecond(vec.begin(), vec.end() - 1); }, 0) },

    { "quick sort first", std::make_pair([](std::vector<int>vec){ quickFirst(vec, 0, static_cast<int>(vec.size() - 1)); }, 0) },
    { "quick sort second", std::make_pair([](std::vector<int>vec){ quickSecond(vec.begin(), vec.end() - 1); }, 0) },

    { "radix sort first", std::make_pair([](std::vector<int>vec){ radixFirst(vec); }, 0) },

    { "selection sort first", std::make_pair([](std::vector<int>vec){ selectionFirst(vec); }, 0) },
    { "selection sort second", std::make_pair([](std::vector<int>vec){ selectionSecond(vec); }, 0) }
};

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

void timeCheck(int min, int max, int size) {
    std::vector<int>testVector;
    for (auto i = 0; i < repetitions; i++) {
        generateVector(testVector, min, max, size);
        for (auto & function : fun) {
            auto start = std::chrono::high_resolution_clock::now();
            function.second.first(testVector);
            auto stop = std::chrono::high_resolution_clock::now();
            function.second.second += std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count(); 
        }
    }
}

void printResult() {
    for (const auto & print : fun) {
        std::cout << print.first << ": avarage time = " << print.second.second / repetitions << '\n';
    }
    std::cout << std::endl;
}
