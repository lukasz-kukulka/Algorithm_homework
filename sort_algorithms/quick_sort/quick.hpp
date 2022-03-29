#include <algorithm>
#include <vector>

template <typename T>
void quickFirst(std::vector<T>& vec, int first, int last) {
    const auto pivot { vec[(first + last) / 2] };
    //auto iterator { first };
    auto greater { 0 };
    if (first == last) {
        return;
    }
    for (auto i = first; i <= last; i++) {
        if (vec[i] < vec[pivot]) {
            std::swap(vec[i], vec[greater++]);
        }
    }
    std::swap(vec[pivot], vec[greater]);
    quickFirst(vec, first, pivot);
    quickFirst(vec, pivot + 1, last);
}

template <typename IT>
void quickSecond(IT first, IT last) {
    first++;
    last++;
}

template <typename T>
void callQuickFirst(std::vector<T> vec) {
    quickFirst(vec, 0, vec.size() - 1);
}

template <typename T>
void callQuickSecond(std::vector<T> vec) {
    
}