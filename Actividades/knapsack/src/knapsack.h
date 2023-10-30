/**
 * @file knapsack.h
 * @brief Dynamic approach to the 0/1 knapsack problem
 * @author Alejandra Cabrera
 * @author Carlos Salguero
 * @author Sergio Garnica
 * @version 1.0.0
 * @date 2023-10-23
 *
 * @copyright Copyright (c) - MIT License
 */

#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <vector>
#include <stdexcept>

/**
 * @brief Soles the 0/1 knapsack problem using dynamic programming.
 *
 * @param[in] max_weight Maximum weight of the knapsack
 * @param[in] weights Vector containing the weights of the items
 * @param[in] values Vector containing the values of the items
 * @param[in] num_items Number of items
 * @return Maximum value that can be obtained with the given weight constraint
 *
 * @note Time Complexity: o(num_items * max_weight)
 * @note Space Complexity: o(max_weight)
 */
int knapsack(int max_weight, const std::vector<int> &weights,
             const std::vector<int> &values, int num_items)
{
  if (weights.size() != values.size())
    throw std::invalid_argument("Mismatch in sizes of input vectors");

  if (weights.size() != num_items)
    throw std::invalid_argument("Mismatch in weights size with num_items");

  for (int i{}; i < num_items; ++i)
  {
    if (weights[i] < 0)
      throw std::invalid_argument("Negative weights are not allowed");

    else if (values[i] < 0)
      throw std::invalid_argument("Negative values are not allowed");
  }

  if (max_weight < 0)
    throw std::invalid_argument("Negative max weight is not allowed");

  std::vector<std::vector<int>> dp(num_items + 1, std::vector<int>(max_weight + 1, 0));

  for (int index{}; index <= num_items; ++index)
  {
    for (int weight = 0; weight <= max_weight; ++weight)
    {
      if (index == 0 || weight == 0)
        dp[index][weight] = 0;
      else if (weights[index - 1] <= weight)
        dp[index][weight] = std::max(dp[index - 1][weight], values[index - 1] + dp[index - 1][weight - weights[index - 1]]);
      else
        dp[index][weight] = dp[index - 1][weight];
    }
  }

  // print values
  std::cout << "Values: ";
  for (int i = 0; i < num_items; ++i)
  {
    std::cout << values[i] << " ";
  }
  std::cout << std::endl;

  // Print the dynamic programming matrix
  for (int i = 0; i < num_items; ++i)
  {
    std::cout << values[i] << ": ";
    for (int j = 0; j <= max_weight; ++j)
    {
      std::cout << dp[i][j] << " ";
    }
    std::cout << std::endl;
  }

  // Print result
  std::cout << "\nOptimal profit: " << dp[num_items][max_weight] << "\n\n";

  return dp[num_items][max_weight];
}

#endif //! KNAPSACK_H