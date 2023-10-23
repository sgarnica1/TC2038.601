#ifndef KNAPSACK_2D_H
#define KNAPSACK_2D_H

#include <vector>
#include <stdexcept>

/**
 * @brief Soles the 0/1 knapsack problem using a 2D dynamic approach.
 *
 * @param[in] max_weight Maximum weight of the knapsack
 * @param[in] weights Vector containing the weights of the items
 * @param[in] values Vector containing the values of the items
 * @param[in] num_items Number of items
 * @return Maximum value that can be obtained with the given weight constraint
 *
 * @note Time Complexity: o(num_items * max_weight)
 * @note Space Complexity: o(num_items * max_weight)
 */
int knapsack_2D(int max_weight, const std::vector<int> &weights,
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

        if (values[i] < 0)
            throw std::invalid_argument(
                "Negative weights are not allowed");
    }

    if (max_weight < 0)
        throw std::invalid_argument("Negative max weight is not allowed");

    std::vector<std::vector<int>> dp(num_items + 1,
                                     std::vector<int>(max_weight + 1, 0));

    for (int i = 1; i <= num_items; ++i)
    {
        for (int w = 1; w <= max_weight; ++w)
        {
            if (weights[i - 1] <= w)
                dp[i][w] = std::max(
                    values[i - 1] + dp[i - 1][w - weights[i - 1]],
                    dp[i - 1][w]);

            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[num_items][max_weight];
}

#endif //! KNAPSACK_2D_H