#include <algorithm>
#include <vector>

template <typename T>
void quickFirst(std::vector<T>& vec, int first, int last) {
    const auto pivot { vec[first] };
    auto greater { first };
    if (first >= last) {
        return;
    }
    for (auto i = first + 1; i <= last; i++) {
        if (vec[i] < pivot) {
            std::swap(vec[i], vec[++greater]);
        }
    }
    std::swap(vec[first], vec[greater]);
    quickFirst(vec, first, greater);
    quickFirst(vec, greater + 1, last);
}

template <typename IT>
void quickSecond(IT first, IT last) {
    first++;
    last++;
}

template <typename T>
void callQuickFirst(std::vector<T>& vec) {
    quickFirst(vec, 0, static_cast<int>(vec.size() - 1));
}

template <typename T>
void callQuickSecond(std::vector<T>& vec) {
    quickSecond(vec.begin(), vec.end());
}