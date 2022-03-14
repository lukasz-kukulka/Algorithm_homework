#include <algorithm>
#include <vector>

void radixFirst(std::vector<int>& vec) { 
    std::vector<std::vector<int>> buckets(10);
    auto bucketLoops { 0 };
    int divider { 1 };
    int iterator { 0 };
    for (int i = *(std::max_element(vec.begin(), vec.end())); i > 0; i = i / 10) {
        bucketLoops++;
    }
    while (bucketLoops > 0) {
        for (auto & ele : vec) {
            buckets[ele / divider % 10].push_back(ele);
        }
        for (auto & ele : buckets) {
            for (auto & eleInside : ele) {
                vec[iterator++] = eleInside;
            }
            ele.clear();
        }
        divider*=10;
        iterator = 0;
        bucketLoops--;
    }
}