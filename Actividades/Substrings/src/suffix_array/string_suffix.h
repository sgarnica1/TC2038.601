/**
 * @file string_suffix.h
 * @brief Calculates an array of substrings and sorts them
 * @author Alejandra Cabrera
 * @author Carlos Salguero
 * @author Sergio Garnica
 * @date 2023-09-23
 * @version 1.0.0
 *
 * @copyright Copyright (c) - MIT License
 *
 */

#ifndef STRING_SUFFIX_H
#define STRING_SUFFIX_H

// C++ Standard Library
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <compare>

/**
 * @brief
 * Receives a string and returns a sorted vector of all possible suffixes
 * @param str String to be processed
 * @return std::vector<std::pair<std::string, int> Sorted vector of all possible
 * @note Time complexity: O(n^2 * log(n)) where n is the size of the string
 * @details
 *      - O(n) for generating all suffixes
 *      - O(n^2 * log(n)) for sorting the suffixes using std::sort
 * @note Space complexity: O(n^2) where n is the size of the string
 */
std::vector<std::pair<std::string, int>> string_suffix(const std::string &str)
{
    std::vector<std::pair<std::string, int>> suffixes;

    for (std::size_t i{}; i < str.size(); ++i)
        suffixes.push_back(std::make_pair(str.substr(i), i));

    std::sort(suffixes.begin(), suffixes.end(),
              [](const auto &lhs, const auto &rhs)
              {
                  return lhs.first < rhs.first;
              });

    return suffixes;
}

#endif //! STRING_SUFFIX_H