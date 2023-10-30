/**
 * @file main.cpp
 * @brief Entry point of the program
 * @author Alejandra Cabrera
 * @author Carlos Salguero
 * @author Sergio Garnica
 * @version 1.0.0
 * @date 2023-10-23
 *
 * @copyright Copyright (c) - MIT License
 */

#include <iostream>
#include <cassert>
#include <vector>

// Project files
#include "knapsack.h"

const std::string RED = "\033[1;31m";
const std::string GREEN = "\033[1;32m";
const std::string RESET = "\033[0m";

/**
 * @brief Tests the knapsack problem
 *
 * @param[in] N Number of items
 * @param[in] values Vector containing the values
 * @param[in] weights Vector containing the weights
 * @param[in] W Max weight allowed
 * @param[in] expected Expected result from the knapsack problem
 */
void test_knapsack(int test_num, int N, const std::vector<int> &values,
                   const std::vector<int> &weights, int W, int expected)
{
  std::cout << "== Test " << test_num << " =="
            << "\n\n";
  int result{knapsack(W, weights, values, N)};

  if (result == expected)
    std::cout << "Test " << test_num << ": "
              << GREEN << " PASSED " << RESET << std::endl;

  else
    std::cout << "Test " << test_num << ": "
              << RED << " FAILED " << RESET
              << " (Expected: " << expected << ", Got: " << result << ")"
              << std::endl;

  std::cout << "\n====================\n\n";
}

int main()
{
  test_knapsack(1, 3, {1, 2, 3},
                {4, 5, 1}, 4, 3);

  test_knapsack(2, 4, {10, 40, 30, 50},
                {5, 4, 6, 3}, 10, 90);

  test_knapsack(3, 5, {60, 100, 120, 130, 75},
                {10, 20, 30, 25, 15}, 50, 265);

  test_knapsack(4, 3, {30, 14, 16},
                {6, 3, 4}, 10, 46);
}