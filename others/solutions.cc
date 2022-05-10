#include "solutions.h"

#include <algorithm>
#include <iostream>

void sortByOrder( std::vector< int >& vec_to_sort, std::vector< int >const & order) 
{
    size_t position_to_swap{};
    for ( size_t i = 0; i < order.size(); ++i )
    {
        for ( size_t j = 0; j < vec_to_sort.size(); ++j )
        {
            if ( order[i] == vec_to_sort[j] ) 
            {
                std::swap( vec_to_sort[position_to_swap++], vec_to_sort[j] );
                break;
            }
        }
    }
    std::sort( vec_to_sort.begin() + position_to_swap, vec_to_sort.end() );
}

std::map < int, int > countFrequency( std::vector< int >const & input_vec)
{
    std::map < int, int > frequency;
    for ( auto const & vec_element : input_vec )
    {
        frequency[vec_element]++;
    }
    return frequency;
}

        // 3. Chapter 15: Find element matching predicate. You need to find a value for which all values on left are lower and on the right are higher.
        // - Example input: `2,3,1,8,7,10,14,12`
        // - Example output: <h>10</h> -> values `2,3,1,8,7` are lower and `14,12` are higher 
        std::tuple<int, std::vector< int >, std::vector < int > >getBeginHightValue( std::vector< int >& input_vec )
        {
            int value;
            std::vector< int > lower_value;
            std::vector< int > greater_value;
            
        }


    void printResult( std::vector< int >const & input_vec )
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

    void printResult( std::map < int, int > map )
    {
        std::string line( 80, '_');
        std::cout << line << '\n';
        std::cout << '{';
        for (auto const& map_element: map )
        {
            std::cout << "{" << map_element.first << "," << map_element.second << "},";
        }
        std::cout << "}" << '\n';

    }
