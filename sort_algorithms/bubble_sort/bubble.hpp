#include <vector>

template <typename T>
void bubble(std::vector<T>& vec) { 
    for (size_t i = 0; i < vec.size(); i++) {
        for (size_t j = 0; j < vec.size() - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

template <typename T>
void bubbleLinear(std::vector<T>& vec) {
    auto iterator = 0;
    for (size_t i = 0; i < vec.size(); iterator++) {
        if (iterator == vec.size() - 1) {
            i++;
            iterator = 0;
        }
        if (vec[iterator] > vec[iterator + 1]) {
            std::swap(vec[iterator], vec[iterator + 1]);
        }
    }
}
