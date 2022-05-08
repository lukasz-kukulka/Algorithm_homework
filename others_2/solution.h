#pragma once

#include <vector>

std::vector< int > triplet_reserve_vec { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
const std::vector< int > find_subsequence_vec { 1, 2, 3, 4, 6, 7, 8, 9, 10, 11 };

void tripletReverse(std::vector<int>& input_vec, const int begin, const int end );


std::vector<int> findSubsequence( std::vector<int> input_vec );

// 3. Chapter 10: Sort a table with given order with memoory complexity <h>O(1)</h>. First table contain numbers and second contain indexes. 
// You need to sort first table by reoredering all elements from first table to index presented on second table. 
// For instance tab1 `1 2 3` order `2 0 1`, so first element <h>1</h> need to be on <h>2</h> index, 
// <h>2</h> element need to be on <h>0</h> index and <h>3</h> element need to be on <h>1</h> index. Result: `2 3 1`.

// - Example input: vec: `{1,2,3,4,5,6}` | order `{2,4,3,5,1,0}`
// - Example output:  `6 5 1 3 2 4`