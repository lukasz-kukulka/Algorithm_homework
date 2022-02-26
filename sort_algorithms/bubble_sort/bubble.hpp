#include <vector>

template <typename T>
void bubble(std::vector<T>& vec) { 
    for (int i = 0; i < vec.size(); i++) {
        for (int j = i; j < vec.size(); j++) {
            if (vec[j] < vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}