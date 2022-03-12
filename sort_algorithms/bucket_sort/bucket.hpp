#include <algorithm>
#include <cmath>
#include <vector>

template <typename T>
void bucketFirst(std::vector<T>& vec) { 
    const auto [first, second] = std::ranges::minmax_element(vec);
    const auto min { *first };
    const auto max { *second };
    std::vector<T> tempVec(max - min + 1);
    for (auto & ele : vec) {
        ++tempVec[ele - min];
    }
    int iterator = 0;
    for (size_t i = 0; i < tempVec.size(); i++) {
        while (tempVec[i] > 0) {
            vec[iterator++] = static_cast<int>(i) + min;
            tempVec[i]--;
        }
    }
}

template <typename T>
void bucketSecond(std::vector<T>& vec) { 
    const auto [first, second] = std::ranges::minmax_element(vec);
    const auto min { *first };
    const auto max { *second };
    std::vector<T> tempVec(max - min + 1);
    for (auto i = vec.begin(); i < vec.end(); i++) {
        ++tempVec[*i - min];
    }
    auto iterator = vec.begin();
    auto sortedIterator = 0;
    for (auto i = tempVec.begin(); i < tempVec.end(); i++) {
        while (*i > 0) {
            *iterator = sortedIterator + min;
            iterator++;
            (*i)--;
        }
        sortedIterator++;
    }
}