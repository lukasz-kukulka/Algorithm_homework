#include <chrono>
#include <functional>
#include <map>
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

std::map<std::string, std::function<void(std::vector<int>)>>fun {
    {"bubble sort first", [](std::vector<int>vec){ bubble(vec); }},
    {"bubble sort second", [](std::vector<int>vec){ bubbleLinear(vec); }},

    {"bucket sort first", [](std::vector<int>vec){ bucketFirst(vec); }},
    {"bucket sort second", [](std::vector<int>vec){ bucketSecond(vec); }},

    {"insert sort first", [](std::vector<int>vec){ insertFirst(vec); }},
    {"insert sort second", [](std::vector<int>vec){ insertSecond(vec); }},

    {"merge sort first", [](std::vector<int>vec){ mergeFirst(vec, 0, static_cast<int>(vec.size() - 1)); }},
    {"merge sort second", [](std::vector<int>vec){ mergeSecond(vec.begin(), vec.end() - 1); }},

    {"quick sort first", [](std::vector<int>vec){ quickFirst(vec, 0, static_cast<int>(vec.size() - 1)); }},
    {"quick sort second", [](std::vector<int>vec){ quickSecond(vec.begin(), vec.end() - 1); }},

    {"radix sort first", [](std::vector<int>vec){ radixFirst(vec); }},

    {"selection sort first", [](std::vector<int>vec){ selectionFirst(vec); }},
    {"selection sort second", [](std::vector<int>vec){ selectionSecond(vec); }}
};