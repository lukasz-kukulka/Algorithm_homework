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
    int const last_index = static_cast < int > ( std::distance( temp_vec.begin(), std::unique(temp_vec.begin(), temp_vec.end() ) ) );
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
            if ( dist > static_cast < int > ( longest_sequence.size() ) )
            {
                longest_sequence.resize( dist );
                std::copy( temp_vec.begin() + first_index_of_checking_sequence, 
                           temp_vec.begin() + last_index_of_checking_sequence, 
                           longest_sequence.begin());
                first_index_of_checking_sequence = last_index_of_checking_sequence;
                if ( last_index - first_index_of_checking_sequence < static_cast < int > ( longest_sequence.size() ) )
                {
                    break;
                }
            }
        }
    }

    return longest_sequence;
}

void sortWithOrder(std::vector<int>& input_vec, std::vector<int>& order )
{
    int iterator{};
    int current_order_index{};
    int prev_num{ input_vec[ current_order_index ] };
    int curent_num{};
    int prev_index{};
    while ( iterator < static_cast < int > ( order.size() ) )
    {
        if ( order[ current_order_index ] != -1 && order [ order[ current_order_index ] ] == current_order_index )
        {
            std::swap ( input_vec[ current_order_index ], input_vec[ order[ current_order_index ] ]);
            order [ order[ current_order_index ] ] = -1;
            order[ current_order_index ] = -1;
            current_order_index++;
            iterator += 2;
        }
        
        else if ( order[current_order_index] == -1 )
        {
            current_order_index++;
        }
        
        else
        {
            curent_num = input_vec[ order[current_order_index] ];
            input_vec[ order[current_order_index] ] = prev_num;
            prev_index = current_order_index;
            current_order_index = order[current_order_index];
            order[prev_index] = -1;
            prev_num = curent_num;
            iterator++;
        }
        printVec(input_vec);
        printVec(order);
    }
}

void printVec( std::vector<int> const& vec )
{
    std::cout << "| ";
    for ( auto const & element : vec )
    {
        std::cout << element << " | "; 
    }
    std::cout << '\n';
}