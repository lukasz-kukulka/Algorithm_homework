#include <array>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>

struct Point {
    int x{};
    int y{};
};


using Matrix = std::vector<std::vector<int>>;
using MatrixSec = std::vector<std::vector<char>>;

void printMatrix( Matrix const & matrix )
{
    for(auto const & line : matrix)
    {
        for ( auto const & ele : line )
        {
            std::cout << "| " << ele << " |";
        }
        std::cout << "\n"; 
    }

}

void printMatrix( MatrixSec const & matrix )
{
    for(auto const & line : matrix)
    {
        for ( auto const & ele : line )
        {
            std::cout << "| " << ele << " |";
        }
        std::cout << "\n"; 
    }

}

Matrix taskOneMatrix{ {-1, 0, -1, -1, -1, 0, 0 }, 
                      {1, -1, -1, -1, 1 ,0, 0 },
                      {-1, 0, -1, 0, -1, -1, -1 }, 
                      {-1, -1, 1, -1, -1, -1, -1 }, 
                      { -1, -1, 0, -1, -1, -1, 0 }, 
                      { 0, 0, -1, -1, 1, 0, 0} };


MatrixSec second = {{'D', 'E', 'H', 'X', 'B'},
                 {'A', 'O', 'G', 'P', 'E'},
                 {'D', 'D', 'C', 'F', 'D'},
                 {'E', 'B', 'E', 'A', 'S'},
                 {'C', 'D', 'Y', 'E', 'N'}};

bool existMove(Matrix const & matrix, Point const & point )
{
    if ( point.x < 0 || point.y < 0 || point.x >= static_cast<int>(matrix.size()) || point.y >= static_cast<int>(matrix.front().size()) )
    {
        return false;
    }
    if ( matrix[ point.x ][ point.y ] != -1 )
    {
        return false;
    }
    return true;
}

int countMovesColour(Matrix & matrix) {
    constexpr uint8_t moves = 4;
    constexpr const std::array<int, moves> moves_x{-1, 0, 0, 1};
    constexpr const std::array<int, moves> moves_y{0, -1, 1, 0};
    std::queue<Point> start_points{};
    int count_moves{};
    for( int i{}; i < static_cast<int>(matrix.size()); ++i )
    {
        for ( int j{}; j < static_cast<int>(matrix.front().size()); ++j)
        {
            if ( matrix[ i ][ j ] > 0 )
            {
                start_points.push( { j, i } );
            }
        }
    }
    
    while( !start_points.empty() )
    {
        count_moves++;
        std::queue<Point> temp = std::move(start_points);
       
        while ( !temp.empty() )
        {
            for (int i{}; i < moves; ++i)
                {
                    auto const point = Point{ temp.front().x + moves_x[i], temp.front().y + moves_y[i]};
                    if ( existMove( matrix, point ) )
                    {
                        start_points.push( { point } );
                        matrix[point.x][point.y] = 1;
                    }
                }
                temp.pop();
        }
    }
    return count_moves;
}

bool isReturnZero ( MatrixSec const & matrix, Point const & point, char ch)
{
    bool out_of_range{ point.x < 0 || point.y < 0 || point.x >= static_cast<int>(matrix.size()) || point.y >= static_cast<int>(matrix.front().size()) };
    if ( ch != '0' && ( out_of_range || ch + 1 != matrix[point.x][point.y] ) )  {
        return true;
    }
    return false;
}

int theLongestSequenceOnePoint ( MatrixSec const & matrix, Point point, char ch )
{
    constexpr int moves = 8;
    int max_length { 1 };
    constexpr const std::array<int, moves> x_moves{-1, -1, -1, 0, 0, 1, 1, 1};
    constexpr const std::array<int, moves> y_moves{-1, 0, 1, 1, -1, -1, 0, 1};

    if ( isReturnZero(matrix, point, ch) ) {
        return 0;
    }

    for (int i = 0; i < moves; ++i) {
        max_length = std::max(max_length,
                              theLongestSequenceOnePoint(matrix, Point { point.x + x_moves[i], point.y + y_moves[i] }, matrix[point.x][point.y]) + 1);
    }
    return max_length;

}

int theLongestSequence ( MatrixSec const & matrix ) {
    int max_sequence{};

    for ( int x{}; x < static_cast < int > ( matrix.size() ); ++x )
    {
        for ( int y{}; y < static_cast < int > ( matrix[x].size() ); ++y )
        {
            max_sequence = std::max( max_sequence, theLongestSequenceOnePoint(matrix, Point{x, y}, '0' ) );
        }
    }

    return max_sequence;
}

int main() {
    printMatrix(taskOneMatrix);
    std::cout << countMovesColour( taskOneMatrix ) << '\n';
    printMatrix(taskOneMatrix);
    std::cout << "--------------------------------------------------------------\n\n";
    printMatrix(second);
    std::cout << theLongestSequence(second) << '\n';
    return 0;
    
}



