#pragma once

#include <vector>
#include <iterator>

namespace Homework{

    namespace TaskOne {
        std::vector< int > toSort {1,2,3,4,5,6};
        std::vector< int > order {4,2,7,8,1};
        void sortByOrder( std::vector< int > vec_to_sort, std::vector< int > order);

    } // namespace TaskOne

    namespace TaskTwo {
        struct FrequencyData {
            int value{};
            int number{};
        }

        std::vector< int > inputVec {1,1,1,1,2,2,2,3,3,4,5,5,5};
        std::vector< FrequencyData > countFrequency( std::vector< int > input_vec);
    } // namespace TaskTwo

    namespace TaskThree {
        std::iterator<int> greater_value_begin{};;
        std::vector< int > inputVec {2,3,1,8,7,10,14,12};
        std::iterator<int> getBeginHightValue( std::vector< int > input_vec );

        // 3. Chapter 15: Find element matching predicate. You need to find a value for which all values on left are lower and on the right are higher.
        // - Example input: `2,3,1,8,7,10,14,12`
        // - Example output: <h>10</h> -> values `2,3,1,8,7` are lower and `14,12` are higher 

    } // namespace TaskThree

    

} // namespace Homework