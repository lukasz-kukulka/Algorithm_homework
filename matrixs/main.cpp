#include <array>
#include <iterator>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using Matrix = std::vector<std::vector<int>>;

template <typename T>
void print(const T& c, std::ostream& os = std::cout) {
    std::copy(std::cbegin(c), std::cend(c), std::ostream_iterator<typename T::value_type>(os, " "));
    os << '\n';
}

template <typename T>
void print2D(const T& c, std::ostream& os = std::cout) {
    std::for_each(cbegin(c), cend(c), [&os](const auto& el) {
        print(el, os);
    });
}

void printSpiral(const Matrix& matrix, std::ostream& os = std::cout) {
    constexpr const std::array<int, 4> moves_y{1, 0, -1, 0};
    constexpr const std::array<int, 4> moves_x{0, 1, 0, -1};
    const int size = static_cast<int>(matrix.size());
    Matrix tmp(size, std::vector<int>(size));
    int y = -1;
    int x = 0;
    int index_x = 0;
    int index_y = 0;
    for (int i = 0; i < (size * 2) - 1; ++i) {
        auto current = i % 4;
        for (int j = 0; j < (size * 2 - i) / 2; ++j) {
            x += moves_x[current];
            y += moves_y[current];
            tmp[x][y] = matrix[index_x][index_y];
            index_y = (index_y + 1) % size;
            if (!index_y) {
                index_x = (index_x + 1) % size;
            }
        }
    }

    print2D(tmp, os);
}

void printSpiralLukasz(const Matrix& matrix, std::ostream& os = std::cout) {
    constexpr const std::array<int, 4> moves_y{0, -1, 0, 1};
    constexpr const std::array<int, 4> moves_x{-1, 0, 1, 0};
    const int size = static_cast<int>(matrix.size());
    Matrix tmp(size, std::vector<int>(size));
    int y = 2;
    int x = 3;
    int index_x = size - 1;
    int index_y = size * size - 1;
    int reverser_x{};
    int reverser_y{};
    for (int i = 0; i < (size * 2) - 1; ++i) {
        auto const current = i % 4;
        int max_index = (size * 2 - i) / 2;
        for (int j = 0; j < max_index; ++j) {
            x += moves_x[current];
            y += moves_y[current];
            tmp[x][y] = matrix[(index_x - reverser_x) % size][(index_y - reverser_y) % size];
            if (!((index_y - reverser_y) % size)) {
                reverser_x++;
            }
            reverser_y++;
        }
    }
    print2D(tmp, os);
}

int main() {
    printSpiral({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    std::cout << '\n';
    printSpiralLukasz({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    std::cout << '\n';
    
    // printSpiral({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}});
    // std::cout << '\n';
}