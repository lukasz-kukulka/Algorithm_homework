#include <vector>

template <typename T>
void insertFirst(std::vector<T>& vec) { 
    for (int i = 0; i < static_cast<int>(vec.size()); i++) {
        for (int j = 0; j < i - 1; j++) {
            if (vec[i] > vec[j]) {
                std::swap(vec[i], vec[j]);
            }
        }
    }
}

template <typename T>
void insertSecond(std::vector<T>& vec) {
    for (auto i = vec.begin(); i < vec.end(); i++) {
        for (auto j = vec.begin(); j < i - 1; j++) {
            if (*i > *j) {
                std::swap(*i, *j);
            }
        }
    }
}