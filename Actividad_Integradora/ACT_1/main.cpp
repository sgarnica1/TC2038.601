/**
 * @file main.cpp
 * @author Carlos Salguero
 * @author Sergio Garnica
 * @author Alejandra Cabrera
 * @brief Implementation of Actividad Integradora 1
 * @version 0.1
 * @date 2023-10-1
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
  std::ifstream inputFile;

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

  return 0;
}