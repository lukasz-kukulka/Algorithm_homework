#pragma once

#include <deque>
#include <iomanip>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

template <typename T>
void print(const T& t, std::ostream& os = std::cout) {
    std::copy(cbegin(t), cend(t), std::ostream_iterator<typename T::value_type>(os, " "));
    os << '\n';
}

template <typename T>
void print2D(const T& t, std::ostream& os = std::cout) {
    std::for_each(cbegin(t), cend(t), [&os](const auto& row) { print(row, os); });
}

int factorial(int num);

int fibb(int num);

class Window {
public:
    Window(size_t size, std::ostream& os = std::cout)
        : size_(size),
          os_(os) {}
    void drawSpiral();
    void drawPattern();
    void drawPattern2();
    void drawLukaszShape();

private:
    using Row = std::vector<char>;
    using Matrix = std::vector<Row>;

    struct Point {
        int x_;
        int y_;

        Point operator+(const Point& other) const {
            return {x_ + other.x_, y_ + other.y_};
        }
        Point operator-(const Point& other) const {
            return {x_ - other.x_, y_ - other.y_};
        }
        bool operator<(const Point& other) const {
            return x_ < other.x_ && y_ < other.y_;
        }
    };

    void fillLine(Matrix& matrix, Point start, Point stop);
    void fillSpiral(Matrix& matrix, Point current, int size);
    void fillPattern(Matrix& matrix, Point current, int size);
    void fillPattern2(Matrix& matrix, Point current, int size);
    void lukaszShape(Matrix& matrix, Point current, int size);

private:
    size_t size_;
    std::ostream& os_;
};

template <typename IT>
double rpn(IT begin, IT end) {
    const std::unordered_map<std::string, double (*)(double, double)> map{
        {"+", [](double lhs, double rhs) { return lhs + rhs; }},
        {"-", [](double lhs, double rhs) { return lhs - rhs; }},
        {"*", [](double lhs, double rhs) { return lhs * rhs; }},
        {"/", [](double lhs, double rhs) { return lhs / rhs; }},
        {"%", [](double lhs, double rhs) { return std::fmod(lhs, rhs); }},
        {"^", [](double lhs, double rhs) { return std::pow(lhs, rhs); }}};
    std::stack<double> stack;
    auto pop_stack = [&stack]() {
        const auto value = stack.top();
        stack.pop();
        return value;
    };

    while (begin != end) {
        std::stringstream ss(*begin);
        if (double value; ss >> value) {
            stack.push(value);
        } else {
            try {
                const auto rhs = pop_stack();
                const auto lhs = pop_stack();
                stack.push(map.at(*begin)(lhs, rhs));
            } catch (const std::out_of_range&) {
                throw std::invalid_argument(*begin);
            }
        }
        ++begin;
    }

    return stack.top();
}

std::vector<std::string> hanoi(int size);

std::vector<std::string> hanoi2(int size);
