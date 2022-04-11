#include "solutions.h"

#include <iostream>
#include <vector>

// You can write and test your homework here :)
int main() {
    {
        std::vector< int > toSort {1,2,3,4,5,6};
        std::vector< int > order {4,2,7,8,1};
        std::cout << "toSort vector before ";
        printResult( toSort );
        std::cout << "order vector";
        printResult( order );
        sortByOrder( toSort, order );
        std::cout << "toSort vector after ";
        printResult( toSort );
    }

    {
        std::vector< int > inputVecTaskTwo {1,1,1,1,2,2,2,3,3,4,5,5,5};
        std::cout << "Vector task two ";
        printResult( inputVecTaskTwo );
        std::cout << "Frequency ";
        printResult( countFrequency( inputVecTaskTwo ) );
    }



    

    std::vector< int > inputVecTaskThree { 2,3,1,8,7,10,14,12 };
    auto val = getBeginHightValue( inputVecTaskThree );
    if ( val.has_value() )
    {
        std::cout << val.value() ;
    }
    else
    {
        std::cout << "NO VALUE\n" ;

    }
    

    return 0;
}
