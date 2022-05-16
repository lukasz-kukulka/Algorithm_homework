#include "solutions.h"
#include <algorithm>
#include <iostream>


// 1. Chapter 3: Reverse triplet in array. For instance you got data: `1 2 3 4 5 6 7 8 9`, after reverse all triplet you got: `3 2 1 6 5 4 9 8 7`, 
// so every triplet is beeing reversed. You also need to handle a range which will be reversed <h>begin</h> and <h>end</h>. 
// - Example input: vec: `1 2 3 4 5 6 7 8 9`, begin: `4` end: <h>7</h>.
// - Example output: `1 2 3 4 7 6 5 8 9` (we reverse only 3 numbers, because in range 4-7 there is one full triplet).
//                            b     e

// - Example input2: vec: `1 2 3 4 5 6 7 8 9`, begin: <h>2</h> end: <h>8</h>.
// - Example output2: `1 2 5 4 3 8 7 6 9` (we reverse 6 numbers, because in range 2-9 there are two full triplets).
//                         b           e
void tripletReverse(std::vector<int>& input_vec, const int begin, const int end )
{
    auto distance = ( end - begin + 1 ) % 3;
    auto triplet_num = distance / 3;
    for ( int i{}; i < distance; i + 3)
    {
        std::swap( input_vec[ begin + i ], input_vec[ begin + i + 2 ]);
    }
}


// 2. Chapter 6: Find longest subsequence, which contain following numbers from range. A range is a sequence of numbers `0 1 2 3...` 
// The numbers don't need to be in sorted order, it could be `3 4 5 0 1 2`. Range don't need to start form <h>0</h>, it could be `5 6 7 8 9`.
// - Example input: `5, 0, 4, 7, 1, 2, 8, 5, 3, 4`
// - Example output: `0, 1, 2, 3, 4, 5` (in any order)

// - Example input2: `0 1 2 3 4 6 7 8 9 10 11`
// - Example output: `6 7 8 9 10 11` (in any order)
std::vector<int> findSubsequence( std::vector<int> const& input_vec )
{

}


// 3. Chapter 10: Sort a table with given order with memoory complexity <h>O(1)</h>. First table contain numbers and second contain indexes. 
// You need to sort first table by reoredering all elements from first table to index presented on second table. 
// For instance tab1 `1 2 3` order `2 0 1`, so first element <h>1</h> need to be on <h>2</h> index, 
// <h>2</h> element need to be on <h>0</h> index and <h>3</h> element need to be on <h>1</h> index. Result: `2 3 1`.

// - Example input: vec: `{1,2,3,4,5,6}` | order `{2,4,3,5,1,0}`
// - Example output:  `6 5 1 3 2 4`
void sortWithOrder(std::vector<int>& input_vec, std::vector<int> const& order )
{

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