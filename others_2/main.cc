#include "solutions.h"
// You can write and test your homework here :)
int main() {
    {
        std::vector< int > taskOneVec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        constexpr int begin_order = 2;
        constexpr int end_order = 8;
        printVec(taskOneVec);
        tripletReverse(taskOneVec, begin_order, end_order );
        printVec(taskOneVec);
    }

    {
        std::vector< int > taskTwoVecA{ 1, 2, 3, 5, 6, 7, 8, 9 };
        std::vector< int > taskTwoVecB{ 5, 0, 4, 7, 1, 2, 8, 5, 3, 4 };
        printVec(taskTwoVecA);
        printVec( findSubsequence( taskTwoVecA ) );
        printVec(taskTwoVecB);
        printVec( findSubsequence( taskTwoVecB ) );
    }
    
}
