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

std::map<std::pair<std::string, float>, std::function<void(std::vector<int>)>>fun {
    {"bubble sort first", 0, [](std::vector<int>vec){ bubble(vec); }},
    {"bubble sort second", 0, [](std::vector<int>vec){ bubbleLinear(vec); }},

    {"bucket sort first", 0, [](std::vector<int>vec){ bucketFirst(vec); }},
    {"bucket sort second", 0, [](std::vector<int>vec){ bucketSecond(vec); }},

    {"insert sort first", 0, [](std::vector<int>vec){ insertFirst(vec); }},
    {"insert sort second", 0, [](std::vector<int>vec){ insertSecond(vec); }},

    {"merge sort first", 0, [](std::vector<int>vec){ mergeFirst(vec, 0, static_cast<int>(vec.size() - 1)); }},
    {"merge sort second", 0, [](std::vector<int>vec){ mergeSecond(vec.begin(), vec.end() - 1); }},

    {"quick sort first", 0, [](std::vector<int>vec){ quickFirst(vec, 0, static_cast<int>(vec.size() - 1)); }},
    {"quick sort second", 0, [](std::vector<int>vec){ quickSecond(vec.begin(), vec.end() - 1); }},

    {"radix sort first", 0, [](std::vector<int>vec){ radixFirst(vec); }},

    {"selection sort first", 0, [](std::vector<int>vec){ selectionFirst(vec); }},
    {"selection sort second", 0, [](std::vector<int>vec){ selectionSecond(vec); }}
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
            function.second(testVector);
            auto stop = std::chrono::high_resolution_clock::now();
            function.first.second += std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count(); 
        }

    }

}
