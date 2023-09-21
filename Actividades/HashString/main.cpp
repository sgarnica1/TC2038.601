/**
 * @file maze_solver.h
 * @author Carlos Salguero
 * @author Sergio Garnica
 * @author Alejandra Cabrera
 * @brief Implementation of Hash Strings
 * @version 0.1
 * @date 2023-09-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
#include "hash_string.h"

int main(int argc, char *argv[])
{
  std::ifstream inputFile;
  int n;

  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " <filename>\n";
    return -1;
  }

  inputFile.open(argv[1]);
  if (!inputFile.is_open())
  {
    std::cout << argv[0] << ": File \"" << argv[1] << "\" not found\n";
    return -1;
  }

  std::cout << "Enter a number between 16 and 64, that must be a multiple of 4: ";
  std::cin >> n;

  if (n < 16 || n > 64 || n % 4 != 0)
  {
    std::cout << "Invalid number\n";
    return -1;
  }

  hash_string(inputFile, n);

  inputFile.close();

  return 0;
}