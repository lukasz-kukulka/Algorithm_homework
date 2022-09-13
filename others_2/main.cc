#include "solutions.h"

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

    {
        std::vector< int > taskThreeVec{ 1,2,3,4,5,6 };
        std::vector< int > taskThreeOrder{ 2,4,3,5,1,0 };
        //std::vector< int > taskThreeOrder{ 5,4,3,2,1,0 };
        //std::vector< int > taskThreeOrder{ 0,1,2,3,4,5 };
        printVec(taskThreeVec);
        sortWithOrder(taskThreeVec, taskThreeOrder );
        printVec( taskThreeVec );
    }
    
}
