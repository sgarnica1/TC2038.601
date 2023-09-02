/**
 * @file main.cpp
 * @author Carlos Salguero
 * @author Sergio Garnica
 * @author Alejandra Cabrera
 * @brief Entry point for the coin change problem
 * @version 0.1
 * @date 2023-09-02
 *
 * @copyright Copyright (c) 2023
 *
 */

// C++ Standard Library
#include <iostream>

// Project Files
#include "coin_change.h"

// Function prototypes
void print_vector(const std::vector<int> &vector);
void test(int change, std::vector<int> &coins);

int main()
{
    int Q = 325, P = 500;
    int change = P - Q;
    std::vector<int> coins{5, 25, 10, 50};
    test(change, coins);

    Q = 160, P = 200;
    change = P - Q;
    coins = {20, 25, 10, 5};
    test(change, coins);

    Q = 85, P = 100;
    change = P - Q;
    coins = {1, 10, 7};
    test(change, coins);

    Q = 711, P = 1000;
    change = P - Q;
    coins = {100, 25, 10, 5, 1};
    test(change, coins);
}

// Function definitions
/**
 * @brief
 * Prints a vector of integers.
 * @param vector The vector to be printed.
 */
void print_vector(const std::vector<int> &vector)
{
    for (const auto &element : vector)
        std::cout << element << " ";

    std::cout << std::endl;
}

/**
 * @brief
 * Tests the greedy and dynamic change algorithms.
 * @param change The change to be computed.
 * @param coins The coins to be used.
 */
void test(int change, std::vector<int> &coins)
{
    std::cout << "Change: " << change << std::endl;
    std::cout << "Coins: ";
    std::sort(coins.begin(), coins.end(),
              std::greater<int>());
    print_vector(coins);

    std::cout << "Greedy change: ";
    print_vector(greedy_change(coins, change));

    std::cout << "Dynamic change: ";
    print_vector(dynamic_change(coins, change));

    std::cout << std::endl;
}