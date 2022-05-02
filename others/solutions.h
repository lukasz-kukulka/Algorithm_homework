#pragma once

#include <vector>

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


    } // namespace TaskThree

} // namespace Homework