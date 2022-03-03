#include <vector>

template <typename T>
void selection(std::vector<T>& vec) {
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