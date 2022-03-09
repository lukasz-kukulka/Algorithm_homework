#include <algorithm>
#include <vector>

template <typename T>
void bucketFirst(std::vector<T>& vec) { 
    const auto [min, max] = std::ranges::minmax_element(vec);
    std::vector<T> tempVec(*max - *min + 1);
    for (auto & ele : vec) {
        ++tempVec[ele - *min];
    }
    int iterator = 0;
    for (int i = 0; i < tempVec.size(); i++) {
        while (tempVec[i] > 0) {
            vec[iterator++] = i + *min;
            tempVec[i]--;
        }
    }
}

template <typename T>
void bucketSecond(std::vector<T>& vec) { 

}