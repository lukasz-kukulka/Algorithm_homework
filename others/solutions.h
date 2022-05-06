#pragma once

#include <vector>
#include <iterator>

void sortByOrder( std::vector< int >& vec_to_sort, std::vector< int >const & order);

struct FrequencyData {
    int value{};
    int number{};
};

std::vector< FrequencyData > countFrequency( std::vector< int >const & input_vec);

void getBeginHightValue( std::vector< int >& input_vec );

void printResult( std::vector< int > input_vec );
    
