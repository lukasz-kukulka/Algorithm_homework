#pragma once

#include <iterator>
#include <map>
#include <vector>

void sortByOrder( std::vector< int >& vec_to_sort, std::vector< int >const & order);

struct FrequencyData {
    int value{};
    int number{};
};

std::map < int, int >  countFrequency( std::vector< int >const & input_vec);

std::tuple<int, std::vector< int >, std::vector< int > > getBeginHightValue( std::vector< int >& input_vec);

void printResult( std::vector< int >const & input_vec );
void printResult( std::map < int, int > map ); 
