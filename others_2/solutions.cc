#include "solutions.h"
#include <algorithm>
#include <iostream>
#include <ranges>

void tripletReverse(std::vector<int>& input_vec, const int begin, const int end )
{
    auto distance = ( end - begin );
    for ( int i{}; i < distance; i = i + 3)
    {
        std::swap( input_vec[ begin + i ], input_vec[ begin + i + 2 ]);
    }
}

std::vector<int> findSubsequence( std::vector<int>const& input_vec )
{
    std::vector < int > longest_sequence{};
    auto temp_vec = input_vec;
    std::sort( temp_vec.begin(), temp_vec.end() );
    int first_index_of_checking_sequence{};
    int last_index_of_checking_sequence{};
    int const last_index = std::distance( temp_vec.begin(), std::unique(temp_vec.begin(), temp_vec.end() ) );
    for ( int i{}; i < last_index; ++i )
    {
        if( ( temp_vec[i] == ( temp_vec[ i + 1 ] - 1 ) ) && ( i + 1  < last_index ) )
        {
            last_index_of_checking_sequence++;
        }
        else
        {
            last_index_of_checking_sequence++;
            auto dist = last_index_of_checking_sequence - first_index_of_checking_sequence;
            if ( dist > longest_sequence.size() )
            {
                longest_sequence.resize( dist );
                std::copy( temp_vec.begin() + first_index_of_checking_sequence, 
                           temp_vec.begin() + last_index_of_checking_sequence, 
                           longest_sequence.begin());
                first_index_of_checking_sequence = last_index_of_checking_sequence;
                if ( last_index - first_index_of_checking_sequence < longest_sequence.size() )
                {
                    break;
                }
            }
        }
    }

    return longest_sequence;
}


// 3. Chapter 10: Sort a table with given order with memory complexity <h>O(1)</h>. First table contain numbers and second contain indexes. 
// You need to sort first table by re-oredering all elements from first table to index presented on second table. 
// For instance tab1 `1 2 3` order `2 0 1`, so first element <h>1</h> need to be on <h>2</h> index, 
// <h>2</h> element need to be on <h>0</h> index and <h>3</h> element need to be on <h>1</h> index. Result: `2 3 1`.

// - Example input: vec: `{1,2,3,4,5,6}` | order `{2,4,3,5,1,0}`
// - Example output:  `6 5 1 3 2 4`
// void sortWithOrder(std::vector<int>& input_vec, std::vector<int> const& order )
// {

// }

void printVec( std::vector<int> const& vec )
{
    std::cout << "| ";
    for ( auto const & element : vec )
    {
        std::cout << element << " | "; 
    }
    std::cout << '\n';
}