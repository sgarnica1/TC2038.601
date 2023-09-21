/**
 * @file main.cpp
 * @author Sergio Garnica
 * @author Alejandra Cabrera
 * @author Carlos Salguero
 * @brief Entry point of the application
 * @version 0.1
 * @date 2023-08-21
 *
 * @copyright Copyright (c) 2023
 *
 */

// C++ Standard Library
#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <chrono>

// Project Files
#include "merge_sort.h"
#include "greedy.h"
#include "dynamic.h"

/**
 * @brief
 * Main function of the application
 * @return int Exit code of the application
 *         (-1 = error, 0 = success, >0 = warning)
 */
int main()
{
  int N, P, Q;
  std::cout << "Enter the number of elements: ";
  std::cin >> N;

  std::vector<int> values(N);

  for (int i{}; i < N; ++i)
  {
    std::cout << "Enter a coin value: $";
    std::cin >> values[i];
  }

  std::cout << "Enter product's cost: $";
  std::cin >> P;

  std::cout << "Enter paid quantity: $";
  std::cin >> Q;

  // Sort currency values
  merge_sort(values.begin(), values.end(),
             std::greater<double>{});

  // Greedy Algorithm
  std::cout << "=============== Greedy Algorithm ===============\n";
  std::vector<int> exchangeValues = greedyExchange(values, P, Q);
  std::cout << "Currencies / Quantity\n";
  for (int i = 0; i < values.size(); i++)
    std::cout << "$" << values[i] << ": " << exchangeValues[i] << "\n";

  // Dynamic Algorithm
  std::cout << "\n=============== Dynamic Algorithm ===============\n";
  std::vector<int> result = dynamicExchange(values, P, Q);
  if (result.empty())
  {
    std::cout << "No valid solution" << std::endl;
  }
  else
  {
    std::cout << "Currencies / Quantity\n";
    for (int i = 0; i < values.size(); i++)
      std::cout << "$" << values[i] << ": " << result[i] << "\n";
  }

  return 0;
}