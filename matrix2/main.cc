#include <string>
#include <vector>

struct Point {
    size_t x{};
    size_t y{};
};

using Matrix = std::vector<std::vector<int>>;

Matrix taskOneMatrix{ {-1, 0, -1, -1, -1, 0, 0 }, 
                      {1, -1, -1, -1, 1 ,0, 0 },
                      {-1, 0, -1, 0, -1, -1, -1 }, 
                      {-1, -1, 1, -1 -1, -1, -1 }, 
                      { -1, -1, 0, -1, -1, -1, 0 }, 
                      { 0, 0, -1, -1, 1, 0, 0} };

Matrix second = {{'D', 'E', 'H', 'X', 'B'},
                 {'A', 'O', 'G', 'P', 'E'},
                 {'D', 'D', 'C', 'F', 'D'},
                 {'E', 'B', 'E', 'A', 'S'},
                 {'C', 'D', 'Y', 'E', 'N'}};

int countMovesColour(Matrix matrix) {

    return static_cast<int>(matrix.size());
}

std::string theLongestSequence ( Matrix const & matrix ) {
    
    return std::to_string( matrix.size()) + "TEST";
}

int main() {
    return 0;
}
