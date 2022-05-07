#pragma once

#include <vector>

std::vector< int > input_vec { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
void tripletReverse(std::vector<int> input_vec, int begin, int end );

// 2. Chapter 6: Find longest subsequence, which contain following numbers from range. A range is a sequence of numbers `0 1 2 3...` 
// The numbers don't need to be in sorted order, it could be `3 4 5 0 1 2`. Range don't need to start form <h>0</h>, it could be `5 6 7 8 9`.
// - Example input: `5, 0, 4, 7, 1, 2, 8, 5, 3, 4`
// - Example output: `0, 1, 2, 3, 4, 5` (in any order)

// - Example input2: `0 1 2 3 4 6 7 8 9 10 11`
// - Example output: `6 7 8 9 10 11` (in any order)


// 3. Chapter 10: Sort a table with given order with memoory complexity <h>O(1)</h>. First table contain numbers and second contain indexes. 
// You need to sort first table by reoredering all elements from first table to index presented on second table. 
// For instance tab1 `1 2 3` order `2 0 1`, so first element <h>1</h> need to be on <h>2</h> index, 
// <h>2</h> element need to be on <h>0</h> index and <h>3</h> element need to be on <h>1</h> index. Result: `2 3 1`.

// - Example input: vec: `{1,2,3,4,5,6}` | order `{2,4,3,5,1,0}`
// - Example output:  `6 5 1 3 2 4`