/**
 * @file merge_sort.h
 * @author Sergio Garnica
 * @author Alejandra Cabrera
 * @author Carlos Salguero
 * @brief Merge sort algorithm implementation
 * @version 0.1
 * @date 2023-08-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

// C++ Standard Library
#include <algorithm>  // std::inplace_merge()
#include <iterator>   // std::next(), std::distance()
#include <functional> // std::less<>()

/**
 * @brief
 * Merge sort algorithm implementation using std::inplace_merge()
 * @tparam BiDirIt Bidirectional iterator type for the container
 * @tparam Compare Comparator type for the container
 * @param first Iterator to the first element in the container
 * @param second Iterator to the second element in the container
 * @param comp Comparator object to sort the container
 * @time_complexity O(N log N)
 * @space_complexity O(N)
 */
template <class BiDirIt, class Compare = std::less<>>
void merge_sort(BiDirIt first, BiDirIt second, Compare comp = Compare{})
{
    auto const N{std::distance(first, second)};

    if (N <= 1)
        return;

    auto const middle{std::next(first, N / 2)};

    merge_sort(first, middle, comp);
    merge_sort(middle, second, comp);

    std::inplace_merge(first, middle, second, comp);
};

#endif //! MERGE_SORT_H