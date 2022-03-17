#include <algorithm>
#include <vector>

void merge() {

}

template <typename T>
void mergeFirst(std::vector<T>& vec, int begin = 0, int end = 0) { 
    auto mid = (end - begin ) / 2;
    if (begin == end) {
        return;
    }
    mergeFirst(vec, begin, mid);
    mergeFirst(vec, mid, end);
    merge();
}

template <typename IT>
void mergeSecond(IT begin, IT end) { 
    std::cout << *begin + *end;
}
