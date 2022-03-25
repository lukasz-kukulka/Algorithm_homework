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
            std::swap(vec[i], vec[greater]);
        } else {
            greater = i;
        }
    }
    std::swap(vec[pivot], vec[greater]);
}

template <typename IT>
void quickSecond(IT first, IT last) {
    first++;
    last++;
}

template <typename T>
void callQuickFirst(std::vector<T> vec) {
    
}