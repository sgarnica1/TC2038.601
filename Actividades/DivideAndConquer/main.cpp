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

/**
 * @brief
 * Main function of the application
 * @return int Exit code of the application
 *         (-1 = error, 0 = success, >0 = warning)
 */
int main()
{
  int N;
  std::cout << "Enter the number of elements: ";
  std::cin >> N;

  std::vector<double> values(N);

  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 mt(seed); // Seed the Mersenne Twister engine with system time
  std::uniform_real_distribution<double> dist(0.0, 100.0);

  for (int i{}; i < N; ++i)
    values[i] = dist(mt);

  std::cout << "Before sorting: ";
  for (auto const &value : values)
    std::cout << value << ", ";

  merge_sort(values.begin(), values.end(),
             std::greater<double>{});

  std::cout << "\nAfter sorting: ";
  for (auto const &value : values)
  {
    std::cout << std::setprecision(6) << value;

    if (&value != &values.back())
      std::cout << ", ";
  }
}