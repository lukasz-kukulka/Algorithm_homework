#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <thread>

#include "solutions.h"

int factorial(int num) {
    if (num < 2) {
        return 1;
    }
    return factorial(num - 1) * num;
}

int fibb(int num) {
    if (num < 2) {
        return num;
    }
    return fibb(num - 1) + fibb(num - 2);
}

void Window::fillLine(Matrix& matrix, Point start, Point stop) {
    // Draw vertial line
    if (start.x_ == stop.x_) {
        std::for_each(begin(matrix) + std::min(stop.y_, start.y_),
                      begin(matrix) + std::max(stop.y_, start.y_),
                      [&](auto& row) {
                          row[start.x_] = '*';
                      });
        return;
    } else if (start.y_ == stop.y_) {
        // Draw horizontal line
        const int width = std::abs(stop.x_ - start.x_) + 1;
        std::fill_n(begin(matrix[start.y_]) + std::min(stop.x_, start.x_), width, '*');
        return;
    }

    // Always draw from bottom (we can also draw for up, it's free choice)
    if (start.y_ > stop.y_) {
        std::swap(start, stop);
    }
    // draw diagonal line (If start.x_ < stop.x_, we draw right so ++x, in other case draw left so --x).
    for (size_t y = start.y_; y < stop.y_; ++y) {
        if (start.x_ < stop.x_)
            matrix[y][start.x_++] = '*';
        else
            matrix[y][--start.x_] = '*';
    }
}

// (1 * 5) + (3 * 4)
// 1 5 * 3 4

void Window::fillSpiral(Matrix& matrix, Point current, int size) {
    if (size <= 0) {
        return;
    }

    const Point right_down = current + Point{size, 0};
    const Point right_up = right_down + Point{0, size};
    const Point left_down = right_up - Point{size, 0};
    const Point left_up = left_down - Point{0, size - 2};
    fillLine(matrix, std::max(Point{0, 0}, current - Point{1, 0}), right_down);
    fillLine(matrix, right_down, right_up);
    fillLine(matrix, right_up, left_down);
    fillLine(matrix, left_down, left_up);
    print2D(matrix, os_);
    //std::this_thread::sleep_for(std::chrono::seconds(2));

    fillSpiral(matrix, left_up + Point{2, 0}, size - 4);


}

void Window::drawSpiral() {
    Matrix matrix(size_ + 1, Row(size_ + 1, ' '));
    fillSpiral(matrix, {0, 0}, size_);
    print2D(matrix, os_);
}

void Window::fillPattern(Matrix& matrix, Point current, int size) {
    if (size <= 0) {
        return;
    }
    const Point top = current;
    const Point left = current - Point{size / 2, size / 2};
    const Point down = current - Point{0, size};
    const Point right = left + Point{size, 0};
    fillLine(matrix, top, right);
    fillLine(matrix, right, down);
    fillLine(matrix, left, down);
    fillLine(matrix, top, left);
    fillPattern(matrix, top - Point{0, 2}, size - 4);
}

void Window::drawPattern() {
    Matrix matrix(size_ + 1, Row(size_ + 1, ' '));
    fillPattern(matrix, {(int)(size_ / 2), (int)size_}, size_);
    print2D(matrix, os_);
}

void Window::fillPattern2(Matrix& matrix, Point current, int size) {
    if (size <= 0) {
        return;
    }
    const Point right = current + Point{size / 2, size / 2};
    const Point top = current + Point{0, size};
    const Point left = right - Point{size, 0};
    const Point down = current;
    fillLine(matrix, current, right);
    fillLine(matrix, right, top);
    fillLine(matrix, top, left);
    fillLine(matrix, left, down);

    // Move to begining
    current = current - Point{size / 2, 0};
    const Point right_down = current + Point{size, 0};
    const Point right_up = right_down + Point{0, size};
    const Point left_down = right_up - Point{size, 0};
    const Point left_up = current;
    fillLine(matrix, current, right_down);
    fillLine(matrix, right_down, right_up);
    fillLine(matrix, right_up, left_down);
    fillLine(matrix, left_down, left_up);

    // Move back to middle
    current = current + Point{size / 2, 0};
    fillPattern2(matrix, current + Point{0, 4}, size - 8);
}

void Window::drawPattern2() {
    Matrix matrix(size_ + 1, Row(size_ + 1, ' '));
    fillPattern2(matrix, {(int)(size_ / 2), 0}, size_);
    print2D(matrix, os_);
}

void hanoi(int size, char src, char tmp, char dst, std::vector<std::string>& moves) {
    if (size == 0)
        return;

    hanoi(size - 1, src, dst, tmp, moves);
    std::stringstream ss;
    ss << "Move: " << size << " | from: " << src << " to: " << dst << '\n';
    moves.push_back(ss.str());
    hanoi(size - 1, tmp, src, dst, moves);
}

std::vector<std::string> hanoi(int size) {
    std::vector<std::string> moves;
    hanoi(size, 'A', 'B', 'C', moves);

    return moves;
}

std::vector<std::string> hanoi2(int size, char src, char tmp, char dst) {
    if (size == 0)
        return {};

    auto first = hanoi2(size - 1, src, dst, tmp);
    std::stringstream ss;
    ss << "Move: " << size << " | from: " << src << " to: " << dst << '\n';
    first.push_back(ss.str());
    auto second = hanoi2(size - 1, tmp, src, dst);
    first.insert(first.end(), std::make_move_iterator(begin(second)), std::make_move_iterator(end(second)));
    return first;
}

std::vector<std::string> hanoi2(int size) {
    return hanoi2(size, 'A', 'B', 'C');
}
