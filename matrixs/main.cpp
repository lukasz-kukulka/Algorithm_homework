#include <array>
#include <iterator>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

struct Point {
    size_t x{};
    size_t y{};
};

using Matrix = std::vector<std::vector<int>>;

template <typename T>
void print( T& c, std::ostream& os = std::cout) {
    std::copy(std::cbegin(c), std::cend(c), std::ostream_iterator<typename T::value_type>(os, " "));
    os << '\n';
}

template <typename T>
void print2D( T& c, std::ostream& os = std::cout) {
    std::for_each(cbegin(c), cend(c), [&os](auto& el) {
        print(el, os);
    });
}

void printSpiralLukasz(Matrix& matrix, std::ostream& os = std::cout) {
    constexpr const std::array<int, 6> moves_y{0, -1,-1, 0, 1};
    constexpr const std::array<int, 6> moves_x{-1, 0, 0, 1, 0};
    int size = static_cast<int>(matrix.size());
    Matrix tmp(size, std::vector<int>(size));
    int y = 2;
    int x = 3;
    int index_x = size - 1;
    int index_y = size * size - 1;
    int steps {};
    int reverser_x{};
    int reverser_y{};
    for (int i = 0; i < (size * 2) - 1; ++i) {
        steps++;
        if (steps == 3){
            x = 1;
            y = 2;
        }
        auto const current = i % 5;
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

void resetMatrixWithZeroValueLukasz( Matrix& matrix, std::ostream& os = std::cout) 
{
    std::vector<Point> zeroPointVec; 
    for (size_t i{}; i < matrix.size(); ++i) {
        for (size_t j{}; j < matrix.begin()->size(); ++j) {
            if (matrix[i][j] == 0) {
                zeroPointVec.push_back( { i, j } );
            }
        }
    }
    for (size_t i{}; i < zeroPointVec.size(); ++i) {
        auto const row = zeroPointVec[i].x;
        auto const col = zeroPointVec[i].y;
        for (size_t j{}; j < matrix.size(); ++j) {
            matrix[row][j] = 0;
            matrix[j][col] = 0;
        }
    }
    print2D(matrix, os);
}

void countValueInMatrixLukasz( Matrix& matrix, int number) {
    int counter = 0;
    int x = 0;
    int y = static_cast<int> ( matrix.size() - 1 );
    while ( x <= static_cast<int> ( matrix.begin()->size() - 1 ) && y >= 0 ) {
        if ( number == matrix[y][x]) {
            y--;
            counter++;
        } else if ( number < matrix[y][x]) {
            y--;
        } else {
            x++;
        }
    }
    std::cout << "Output for number " << number << ": " << counter;
}

int main() {
    Matrix matrixFirst ={ {1, 2, 3}, 
                          {4, 5, 6}, 
                          {7, 8, 9} };
    printSpiralLukasz( matrixFirst );
    std::cout << '\n';

    Matrix matrixSecond = {  { 1, 1, 1, 1, 0 },
                             { 1, 0, 1, 1, 1 },
                             { 1, 1, 1, 1, 1 },
                             { 1, 1, 1, 1, 1 },
                             { 0, 1, 1, 1, 1 } };
    print2D(matrixSecond, std::cout);
    std::cout << '\n';
    resetMatrixWithZeroValueLukasz ( matrixSecond );
    std::cout << '\n';

    Matrix matrixThird = {  {-5, -2, -1, 3,  4}, 
                            {-3, -2, -1, 4,  6},
                            {-2, -1,  0, 5,  8}, 
                            {-1,  3,  6, 10, 12}, 
                            { 5,  8, 10, 13, 15} };
    print2D(matrixThird, std::cout);
    std::cout << '\n';
    countValueInMatrixLukasz ( matrixThird, 3 );
    std::cout << '\n';
    countValueInMatrixLukasz ( matrixThird, 4 );
    std::cout << '\n';
    countValueInMatrixLukasz ( matrixThird, -1 );
    std::cout << '\n';
}