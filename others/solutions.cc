#include "solutions.h"

#include <algorithm>
#include <iostream>


        // 1. Chapter 9: Sort element by order presented in second table. In both tables there could be any values. 
        // You need to focus only on valid values and make sort operation.If there is no value in `order` table you need to sort it at the end of `toSort` vector.
        // - Example input: `toSort {1,2,3,4,5,6}` `order {4,2,7,8,1}`
        // - Example output: `{4,2,1,3,5,6}`
        void sortByOrder( std::vector< int >& vec_to_sort, std::vector< int >const & order) 
        {
            size_t position_to_swap{};
            for ( size_t i = 0; i < order.size(); ++i )
            {
                for ( size_t j = 0; j < vec_to_sort.size(); ++j )
                {
                    if ( order[i] == vec_to_sort[j] ) 
                    {
                        std::swap( vec_to_sort[i], vec_to_sort[position_to_swap] );
                        position_to_swap++;
                        break;
                    }
                }

            }
            std::sort( vec_to_sort.begin() + position_to_swap, vec_to_sort.end() );
        }

        // 2. Chapter 13: Find frequency of each value in sorted vector
        // - Example input: `1,1,1,1,2,2,2,3,3,4,5,5,5`
        // - Example output: `{{1,4},{2,3},{3,2},{4,1},{5,3}}`
        std::vector< FrequencyData > countFrequency( std::vector< int >const & input_vec)
        {
            
            std::vector< FrequencyData > frequency;
            std::cout << input_vec.size();
            return frequency;
        }

        // 3. Chapter 15: Find element matching predicate. You need to find a value for which all values on left are lower and on the right are higher.
        // - Example input: `2,3,1,8,7,10,14,12`
        // - Example output: <h>10</h> -> values `2,3,1,8,7` are lower and `14,12` are higher 
        void getBeginHightValue( std::vector< int >& input_vec )
        {
            input_vec[0] = 0;
        }


    void printResult( std::vector< int > input_vec )
    {
        std::string line( 80, '_');
        std::cout << line << '\n';
        std::cout << '|';
        for (auto const& vec_element: input_vec )
        {
            std::cout << ' ' << vec_element;
        }
        std::cout << " |" << '\n';

    }
