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
        std::optional < int > getBeginHightValue( std::vector< int >& input_vec )
        {
            if ( input_vec.size() < 3 )
            {
                // does make sense check matching for vector smaller than three elements
                return std::nullopt;
            }
            int greater{};
            int match_index{};
            for ( size_t i = 0; i < input_vec.size(); ++i )
            {
                if ( greater < input_vec[i])
                {
                    greater = input_vec[i];
                }
                //std::cout << "i = " << i << ", greater = " << greater << ", input_vec[i] =  " << input_vec[i] << ", input_vec[i + 1] =  " << input_vec[i + 1] << '\n';
                auto is_greater = std::all_of( ( input_vec.begin() + i ), input_vec.end(), [ = ]( auto ele ){ 
                    //std::cout << " ele = " << ele << "\n";
                    return greater <= ele; } );
                if ( is_greater )
                {
                    return i;
                }
                
            }
            return std::nullopt;
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
