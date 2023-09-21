/**
 * @file dynamic.h
 * @author Sergio Garnica
 * @author Alejandra Cabrera
 * @author Carlos Salguero
 * @brief Currency exchange problem dynamic algorithm implementation
 * @version 0.1
 * @date 2023-08-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DYNAMIC_H
#define DYNAMIC_H

// C++ Standard Library
#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

/**
 * @brief
 * Currency exchange problem dynamic algorithm implementation
 * @param currencies Vector of currencies values
 * @param cost Cost of the product
 * @param paidAmount Paid amount
 * @time_complexity O(N)
 * @space_complexity O(N)
 */
std::vector<int> dynamicExchange(std::vector<int> currencies, int cost, int paidAmount)
{
  // Calculate the maximum possible value for the amount
  int change = paidAmount - cost + 1;

  // Create a vector to store the minimum number of coins needed for each amount
  std::vector<int> dp(change, INT_MAX);

  // Initialize the minimum number of coins needed for 0 as 0
  dp[0] = 0;

  // Iterate through each currency denomination
  for (int coin : currencies)
  {
    // Update the minimum number of coins needed for each amount
    for (int amount = coin; amount < change; amount++)
    {
      std::cout << "Amount: " << amount << ", Coin: " << coin << "\n";
      if (dp[amount - coin] != INT_MAX)
      {
        dp[amount] = std::min(dp[amount], dp[amount - coin] + 1);
      }
    }
  }

  // If dp[paidAmount - cost] is still INT_MAX, it means it's not possible to make change
  if (dp[change - 1] == INT_MAX)
  {
    return std::vector<int>(); // No valid solution
  }

  // Reconstruct the solution (list of currency counts)
  std::vector<int> exchange_values(currencies.size(), 0);
  int remaining = change - 1;

  for (int i = currencies.size() - 1; i >= 0; i--)
  {
    while (remaining >= currencies[i] && dp[remaining] == dp[remaining - currencies[i]] + 1)
    {
      exchange_values[i]++;
      remaining -= currencies[i];
    }
  }

  return exchange_values;
}
#endif //! DYNAMIC_H