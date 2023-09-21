/**
 * @file greedy.h
 * @author Sergio Garnica
 * @author Alejandra Cabrera
 * @author Carlos Salguero
 * @brief Currency exchange problem greedy algorithm implementation
 * @version 0.1
 * @date 2023-08-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef GREEDY_H
#define GREEDY_H

// C++ Standard Library
#include <iostream>
#include <vector>

/**
 * @brief
 * Currency exchange problem greedy algorithm implementation
 * @param currencies Vector of currencies values
 * @param cost Cost of the product
 * @param quantity Paid amount
 * @time_complexity O(N)
 * @space_complexity O(N)
 */
std::vector<int> greedyExchange(std::vector<int> currencies, int cost, int quantity)
{
  std::vector<int> exchange_values(currencies.size());

  if (cost >= quantity)
    return exchange_values;

  int returnQuantity = quantity - cost;

  int iterator = 0;
  while (returnQuantity > 0)
  {

    if (returnQuantity - currencies[iterator] < 0)
    {
      exchange_values[iterator] = exchange_values[iterator] == 0 ? 0 : exchange_values[iterator];
      iterator++;
    }

    if (returnQuantity - currencies[iterator] == 0)
    {
      exchange_values[iterator]++;
      returnQuantity = 0;
    }

    if (returnQuantity - currencies[iterator] > 0)
    {
      exchange_values[iterator]++;
      returnQuantity -= currencies[iterator];
    }
  }

  return exchange_values;
}

#endif //! GREEDY_H