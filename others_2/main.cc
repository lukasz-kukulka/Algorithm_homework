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
        std::vector< int > taskTwoVec{ 1, 2, 3, 5, 6, 7, 8, 9 };
        findSubsequence( taskTwoVec );
    }
    
}
