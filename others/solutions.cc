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

std::optional < int > getBeginHightValue( std::vector< int >& input_vec )
{
    int greater{};
    int match_index{};
    for ( size_t i = 0; i < input_vec.size(); ++i )
    {
        if ( greater < input_vec[i])
        {
            greater = input_vec[i];
        }
        auto is_greater = std::all_of( ( input_vec.begin() + i ), input_vec.end(), [ = ]( auto ele ){ 
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

    void printResult( std::vector< int >const & input_vec, std::optional < int > separate_index )
    {
        if (!separate_index.value())
        {
            std::cout << "NO VALUE\n";
        }
        else
        {
            auto val = separate_index.value();
            std::string line( 80, '_');
            std::cout << line << '\n';
            std::cout << input_vec[ val ] << " -> values '";
            for ( int i = 0; i < val; ++i )
            {
                std::cout << input_vec[i] << ",";
            }
            std::cout << "' are lower and '";
            for ( int i = val + 1; i < input_vec.size(); ++i )
            {
                std::cout << input_vec[i] << ",";
            }
            std::cout << "` are higher " << '\n';
        }
    }
