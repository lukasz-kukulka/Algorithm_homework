#include <vector>
#include <algorithm>

template <typename T>
void selectionFirst(std::vector<T>& vec) {
    int tempValue { };
    for (int i = 0; i < vec.size(); i++) {
        tempValue = i;
        for (int j = i; j < vec.size() - 1; j++) {
            if (vec[tempValue] > vec[j + 1]) {
                tempValue = j + 1;
            }
        }
        std::swap(vec[i], vec[tempValue]);
    }
}

template <typename T>
void selectionSecond(std::vector<T>& vec) {
    auto tempValue { vec.begin() };
    for (auto i = vec.begin(); i < vec.end(); i++) {
        tempValue = std::min_element(i, vec.end());
        std::swap(*i, *tempValue);
    }
}