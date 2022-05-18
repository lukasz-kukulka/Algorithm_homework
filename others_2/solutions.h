#pragma once

#include <vector>

// std::vector< int > triplet_reserve_vec { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
// const std::vector< int > find_subsequence_vec { 1, 2, 3, 4, 6, 7, 8, 9, 10, 11 };
// std::vector< int > toSort { 1, 2, 3, 4, 5, 6 };
// std::vector< int > order { 2, 4, 3, 5, 1, 0 };

void tripletReverse(std::vector<int>& input_vec, const int begin, const int end );
std::vector<int> findSubsequence( std::vector<int> input_vec );
void sortWithOrder(std::vector<int>& input_vec, std::vector<int> const& order );

void printVec( std::vector<int> const& vec );
