#include <algorithm>
#include <vector>

template <typename T>
void merge(std::vector<T>& vec, T begin, T mid, T end) {
    std::vector<T> temp(end - begin + 1);
    auto beginTemp = begin;
    auto midTemp = mid + 1;
    for (auto i = 0; i <= end - begin; i++) {
        if ((vec[beginTemp] < vec[midTemp] && beginTemp <= mid) || midTemp > end) {
            temp[i] = vec[beginTemp++];
        } else {
            temp[i] = vec[midTemp++];
        }
    }
    std::copy(temp.begin(), temp.end(), vec.begin() + begin);
}

template <typename T>
void mergeFirst(std::vector<T>& vec, T begin, T end) { 
    auto mid = (end + begin ) / 2;
    if (begin == end) {
        return;
    }
    mergeFirst(vec, begin, mid);
    mergeFirst(vec, mid + 1, end);
    merge(vec, begin, mid, end);    
}

template <typename IT>
void mergeSecond(IT begin, IT end) { 
    auto temp = *begin + *end;
    temp++;
}
