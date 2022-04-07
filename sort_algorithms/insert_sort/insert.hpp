#include <vector>

template <typename T>
void insert(std::vector<T>& vec) { 
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < i - 1; j++) {
            if (vec[i] > vec[j]) {
                std::swap(vec[i], vec[j]);
            }
        }
    }
}