/**
 * @file knapsack.h
 * @brief Dynamic approach to the 0/1 knapsack problem
 * @author Alejandra Cabrera
 * @author Carlos Salguero
 * @author Sergio Garnia
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
        throw std::invalid_argument("Mistach in weights size with num items");

    for (int i{}; i < num_items; ++i)
    {
        if (weights[i] < 0)
            throw std::invalid_argument(
                "Negative values are not allowed");

        else if (values[i] < 0)
            throw std::invalid_argument(
                "Negative weights are not allowed");
    }

    if (max_weight < 0)
        throw std::invalid_argument("Negative max weight is not allowed");

    std::vector<int> dp(max_weight + 1, 0);

    for (int index{}; index < num_items; ++index)
        for (int weight = max_weight; weight >= weights[index]; --weight)
            dp[weight] = std::max(dp[weight],
                                  values[index] + dp[weight - weights[index]]);

    return dp[max_weight];
}

#endif //! KNAPSACK_H