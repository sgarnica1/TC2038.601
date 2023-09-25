/**
 * @file main.cpp
 * @brief Entry point for the program
 * @author Alejandra Cabrera
 * @author Carlos Salguero
 * @author Sergio Garnica
 * @date 2023-09-23
 * @version 1.0.0
 *
 * @copyright Copyright (c) - MIT License
 *
 */

#include <iostream>

// Project files
#include "suffix_array/string_suffix.h"

// Function prototypes
void print_suffixes(const std::vector<std::pair<std::string, int>> &suffixes);

template <typename vector>
void assert_cases(const vector &suffixes, const vector &expected_suffixes);

// Namespace aliases
namespace ColorOutput
{
  const std::string RED = "\033[31m";
  const std::string GREEN = "\033[32m";
  const std::string RESET = "\033[0m";
}

/**
 * @brief
 * Main function of the program. The expected output was taken from
 * http://www.allisons.org/ll/AlgDS/Strings/Suffix/
 * @return int
 */
int main()
{
  auto suffixes = string_suffix("banana");
  std::vector<std::pair<std::string, int>> expected = {{"a", 5},
                                                       {"ana", 3},
                                                       {"anana", 1},
                                                       {"banana", 0},
                                                       {"na", 4},
                                                       {"nana", 2}};

  std::cout << "Test Case 1 - banana" << std::endl;
  assert_cases(suffixes, expected);

  suffixes = string_suffix("mississippi");
  expected = {{"i", 10},
              {"ippi", 7},
              {"issippi", 4},
              {"ississippi", 1},
              {"mississippi", 0},
              {"pi", 9},
              {"ppi", 8},
              {"sippi", 6},
              {"sissippi", 3},
              {"ssippi", 5},
              {"ssissippi", 2}};

  std::cout << "Test Case 2 - mississippi" << std::endl;
  assert_cases(suffixes, expected);

  suffixes = string_suffix("abracadabra");
  expected = {{"a", 10},
              {"abra", 7},
              {"abracadabra", 0},
              {"acadabra", 3},
              {"adabra", 5},
              {"bra", 8},
              {"bracadabra", 1},
              {"cadabra", 4},
              {"dabra", 6},
              {"ra", 9},
              {"racadabra", 2}};

  std::cout << "Test Case 3 - abracadabra" << std::endl;
  assert_cases(suffixes, expected);

  suffixes = string_suffix("ababaa");
  expected = {{"a", 5},
              {"aa", 4},
              {"abaa", 2},
              {"ababaa", 0},
              {"baa", 3},
              {"babaa", 1}};

  std::cout << "Test Case 4 - ababaa" << std::endl;
  assert_cases(suffixes, expected);

  suffixes = string_suffix("suffixarraysarecool");
  expected = {{"arecool", 12},
              {"arraysarecool", 6},
              {"aysarecool", 9},
              {"cool", 15},
              {"ecool", 14},
              {"ffixarraysarecool", 2},
              {"fixarraysarecool", 3},
              {"ixarraysarecool", 4},
              {"l", 18},
              {"ol", 17},
              {"ool", 16},
              {"raysarecool", 8},
              {"recool", 13},
              {"rraysarecool", 7},
              {"sarecool", 11},
              {"suffixarraysarecool", 0},
              {"uffixarraysarecool", 1},
              {"xarraysarecool", 5},
              {"ysarecool", 10}};

  std::cout << "Test Case 5 - suffixarraysarecool" << std::endl;
  assert_cases(suffixes, expected);
}

// Function definitions
/**
 * @brief
 * Prints the suffixes and their indexes to the console
 * @param suffixes Vector of pairs of strings and integers
 */
void print_suffixes(const std::vector<std::pair<std::string, int>> &suffixes)
{
  for (const auto &suffix : suffixes)
    std::cout << suffix.second << " " << suffix.first << std::endl;

  std::cout << std::endl;
}

/**
 * @brief
 * Asserts that the suffixes are the same as the expected suffixes
 * @param suffixes Vector of pairs of strings and integers
 * @param expected_suffixes Vector of pairs of strings and integers
 * @param case Test case number
 */
template <typename vector>
void assert_cases(const vector &suffixes, const vector &expected_suffixes)
{
  using namespace ColorOutput;

  if (suffixes == expected_suffixes)
  {
    std::cout << GREEN << "Test case passed" << RESET << std::endl;
    return;
  }

  std::cout << RED << "Test case failed" << RESET << std::endl;

  for (std::size_t i{};
       i < std::min(suffixes.size(), expected_suffixes.size()); ++i)
  {
    if (suffixes[i] != expected_suffixes[i])
    {
      std::cout << RED << "Mismatch at index " << i << ": "
                << "Expected (" << expected_suffixes[i].second
                << ", " << expected_suffixes[i].first
                << "), Got (" << suffixes[i].second << ", "
                << suffixes[i].first << ")" << RESET << std::endl;

      break;
    }
  }

  std::cout << "Expected:" << std::endl;
  print_suffixes(expected_suffixes);

  std::cout << "Actual:" << std::endl;
  print_suffixes(suffixes);
}