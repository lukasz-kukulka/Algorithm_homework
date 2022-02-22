#include <bitset>
#include <chrono>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <random>
#include <string>
#include <type_traits>
#include <vector>

using namespace std::chrono_literals;

std::vector<int> getVec(size_t size) {
    std::random_device rd;
    std::mt19937 seed(rd());
    std::uniform_int_distribution<int> dist(0, 12);
    std::vector<int> vec(size);
    std::generate(begin(vec), end(vec), [&]() { return dist(seed); });

    return vec;
}

void separator() {
    std::cout << '\n'
              << std::string(80, '-') << '\n';
}

template <typename T, typename FUN, typename E = typename T::value_type>
void printAllOccunrences(const T& vec, const E& value, FUN fun) {
    auto it = std::cbegin(vec);
    while (it != std::cend(vec)) {
        it = fun(it, std::cend(vec), value);
        if (it == std::cend(vec)) {
            return;
        }
        std::cout << "VALUE (" << value << ") at pos: " << std::distance(std::cbegin(vec), it) << '\n';
        ++it;
    }
}

template <typename T>
void printW(const T& t, int width) {
    for (const auto& el : t) {
        std::cout << std::setw(width) << el << ' ';
    }
    std::cout << '\n';
}

template <typename T, typename C>
bool isEqual(const T& lhs, const T& rhs, C comp) {
    return !comp(lhs, rhs) && !comp(rhs, lhs);
}

void printIndex(int counter) {
    int i = 0;
    while (counter--) {
        std::cout << std::setw(2) << i++ << ' ';
    }
    std::cout << '\n';
}

template <typename IT, typename E, typename C>
IT lowerBoundHelper(IT left, IT right, const E& value, C comp) {
    if (left > right) {
        return left;
    }

    const size_t distance = std::distance(left, right) / 2;
    const IT mid = std::next(left, distance);

    if (isEqual(*mid, value, comp) || comp(*mid, value)) {
        return lowerBoundHelper(left, std::prev(mid), value, comp);
    }
    return lowerBoundHelper(std::next(mid), right, value, comp);
}

template <typename IT, typename E = typename IT::value_type, typename C = std::greater<E>>
IT lowerBound(IT first, IT last, const E& value, C comp = C{}) {
    const auto it = lowerBoundHelper(first, last, value, comp);
    return it > last ? last : it;
}

template <typename IT, typename E, typename C>
IT upperBoundHelper(IT left, IT right, const E& value, C comp) {
    if (left > right) {
        return left;
    }
    const size_t distance = std::distance(left, right) / 2;
    IT mid = std::next(left, distance);

    if (comp(*mid, value)) {
        return upperBoundHelper(left, std::prev(mid), value, comp);
    }
    return upperBoundHelper(std::next(mid), right, value, comp);
}

template <typename IT, typename E = typename IT::value_type, typename C = std::greater<E>>
IT upperBound(IT first, IT last, const E& value, C comp = C{}) {
    const auto it = upperBoundHelper(first, last, value, comp);
    return it > last ? last : it;
}

// begin namespace luk ////////////////////////////////////////////////////////
namespace luk {
    template <typename IT, typename E, typename C>
    IT lowerBoundHelper(IT left, IT right, const E& value, C comp) {
        size_t distance = std::distance(left, right) / 2;
        IT mid = std::next(left, distance);
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "-----------   BEFORE   -------------" << std::endl;
        std::cout << "LEFT = " << *left << "        MID = " << *mid << "       RIGHT =  " << *right << "       DISTANCE = " << distance << std::endl;
        std::cout << std::endl;
        std::getchar();
        while (left < mid) {
            if (comp(value, *mid)) {
                left = mid;
                distance = std::distance(mid, right) / 2;
                mid = std::next(mid, distance);
                std::cout << "-----------   IF   -------------" << std::endl;
                std::cout << "LEFT = " << *left << "        MID = " << *mid << "       RIGHT =  " << *right << "       DISTANCE = " << distance << std::endl;
                std::cout << std::endl;
            } else {
                right = std::next(mid);
                distance = std::distance(left, mid) / 2;
                mid = std::next(left, distance);

                //mid = std::prev(right, distance);
                std::cout << "-----------   ELSE   -------------" << std::endl;
                std::cout << "LEFT = " << *left << "        MID = " << *mid << "       RIGHT =  " << *right << "       DISTANCE = " << distance << std::endl;
                std::cout << std::endl;
            }
            //IT mid = std::next(left, distance);
            std::getchar();
        }
        std::cout << std::endl;
        std::cout << "RETURN : ";
        return std::next(left);
    }

    template <typename IT, typename E = typename IT::value_type, typename C = std::greater<E>>
    IT lowerBound(IT first, IT last, const E& value, C comp = C{}) {
        const auto it = lowerBoundHelper(first, last, value, comp);
        return it > last ? last : it;
    }

    template <typename IT, typename E, typename C>
    IT upperBoundHelper(IT left, IT right, const E& value, C comp) {

    }

    template <typename IT, typename E = typename IT::value_type, typename C = std::greater<E>>
    IT upperBound(IT first, IT last, const E& value, C comp = C{}) {
        const auto it = upperBoundHelper(first, last, value, comp);
        return it > last ? last : it;
    }
} // end namespace luk //////////////////////////////////////////////////////////////////////////////////////

int main() {
    auto vec = getVec(7);
    std::sort(begin(vec), end(vec));
    printIndex(7);
    printW(vec, 2);
    std::cout << "B) First pos of 7: " << std::distance(vec.cbegin(), lowerBound(vec.cbegin(), vec.cend(), 7)) << '\n';
    std::cout << "B) Last pos of 7: " << std::distance(vec.cbegin(), upperBound(vec.cbegin(), vec.cend(), 7)) << '\n';
    separator();

    std::cout << "C) First pos of 7: " << std::distance(vec.cbegin(), luk::lowerBound(vec.cbegin(), vec.cend(), 7)) << '\n';
   // std::cout << "C) Last pos of 7: " << std::distance(vec.cbegin(), luk::upperBound(vec.cbegin(), vec.cend(), 7)) << '\n';
    separator();

    return 0;
}