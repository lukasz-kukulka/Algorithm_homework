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

#include "solutions.h"

using namespace std::chrono_literals;

std::vector<int> getVec(size_t size) {
    std::random_device rd;
    std::mt19937 seed(rd());
    std::uniform_int_distribution<int> dist(0, 20);
    std::vector<int> vec(size);
    std::generate(begin(vec), end(vec), [&]() {
        return dist(seed);
    });

    return vec;
}

void separator() {
    std::cout << '\n'
              << std::string(80, '-') << '\n';
}

template <typename T>
bool isSame(const T& lhs, const T& rhs) {
    return std::equal(cbegin(lhs), cend(lhs), cbegin(rhs), cend(rhs));
}

int main() {
    std::cout << "5! = " << factorial(5) << '\n';
    std::cout << "fibb(10): " << fibb(10) << '\n';
    std::cout << "fibb(15): " << fibb(15) << '\n';
    std::cout << "fibb(20): " << fibb(20) << '\n';
    std::cout << '\n';

    Window window(32);
    window.drawSpiral();
    std::cout << '\n';
    window.drawPattern();
    std::cout << '\n';
    window.drawPattern2();

    std::vector<std::string> vec{"3", "1", "2", "+", "*", "2", "/"};
    std::cout << rpn(vec.cbegin(), vec.cend()) << '\n';
    vec = {"8", "7", "+", "3", "/", "2", "*", "4", "+", "2", "^"};
    std::cout << rpn(vec.cbegin(), vec.cend()) << '\n';
    // call it by -> echo "8 7 + 3 / 2 * 4 + 2 ^" | .\Module2.exe
    // std::cout << rpn(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>{}) << '\n';

    // std::cout << '\n';
    // print(hanoi(4));
    // std::cout << '\n';
    // print(hanoi2(4));

    print(hanoi(3));

    // std::cout << "isSame?: " << std::boolalpha << isSame(hanoi(6), hanoi2(6)) << '\n';
}
