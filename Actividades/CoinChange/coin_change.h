/**
 * @file coin_change.h
 * @author Sergio Garnica
 * @author Carlos Salguero
 * @author Alejandra Cabrera
 * @brief Coing change problems with dynamic and greedy algorithms
 * @version 0.1
 * @date 2023-08-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef COIN_CHANGE_H
#define COIN_CHANGE_H

#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>

/**
 * @brief
 * Computes the change using dynamic programming.
 * @param denomination The avaiable coins
 * @param change The change to be computed
 * @return std::vector<int> The number of coins to give as change.
 * @time_complexity O(n * change) where n is the number of coins and change
 *                         is the change to be computed
 * @space_complexity O(n * change) where n is the number of coins and change
 *                        is the change to be computed
 */
std::vector<int> dynamic_change(const std::vector<int> &denomination,
                                int change)
{
    std::size_t size{denomination.size()};
    std::vector<int> min_coins(change + 1);
    std::unordered_map<int, std::vector<int>> coins_used;

    std::fill(min_coins.begin(), min_coins.end(),
              std::numeric_limits<int>::max() - 1);

    min_coins[0] = 0;
    coins_used.emplace(0, std::vector<int>(size, 0));

    for (int i{1}; i <= change; i++)
    {
        for (int j{}; j < size; j++)
        {
            if (denomination[j] <= i &&
                min_coins[i - denomination[j]] + 1 < min_coins[i])
            {
                min_coins[i] = min_coins[i - denomination[j]] + 1;
                coins_used[i] = coins_used[i - denomination[j]];
                coins_used[i][j]++;
            }
        }
    }

    return coins_used[change];
}

/**
 * @brief
 * Computes the change using greedy algorithm.
 * @param denomination The avaiable coins
 * @param change The change to be computed
 * @return std::vector<int> The number of coins to give as change.
 * @time_complexity O(n)
 * @space_complexity O(n)
 */
std::vector<int> greedy_change(const std::vector<int> &denominations,
                               int change)
{
    std::vector<int> coins_used(denominations.size(), 0);

    for (int i = 0; i < denominations.size(); i++)
    {
        coins_used[i] = change / denominations[i];
        change -= coins_used[i] * denominations[i];
    }

    return coins_used;
}

#endif //! COIN_CHANGE_H