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
// void mergeSecond(IT left, IT right) { 
//     if (left >= right) {
//         return;
//     }
//     int distance = static_cast<int>(std::distance(left, right) / 2);
//     IT mid = std::next(left, distance);
//     mergeSecond(left, mid);
//     mergeSecond(std::next(mid), right);

//     std::vector<typename IT::value_type> tmp;
//     tmp.reserve(std::distance(left, right) + 1);
//     std::merge(left, std::next(mid), std::next(mid), std::next(right), std::back_inserter(tmp));
//     std::copy(tmp.begin(), tmp.end(), left);
// }
void mergeSecond(IT begin, IT end) { 
    if (begin >= end) {
        return;
    }
    const auto mid = (std::next(begin, std::distance(begin, end) / 2) + 1);
    mergeSecond(begin, std::prev(mid));
    mergeSecond(mid, end);
    std::vector<typename IT::value_type>tempVec;
    tempVec.reserve((std::distance(begin, end) + 1));
    std::merge(begin, mid, mid, std::next(end), std::back_inserter(tempVec));
    std::copy(tempVec.begin(), tempVec.end(), begin);

}
