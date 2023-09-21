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

  // Determine the length of the file
  inputFile.seekg(0, std::ios::end);
  int fileLength = inputFile.tellg();
  inputFile.seekg(0, std::ios::beg);

  std::cout << "Filesize: " << fileLength << std::endl;

  // Calculate the desired column size
  double rowSize = static_cast<double>(fileLength) / static_cast<double>(n);
  std::cout << "Row size: " << std::ceil(rowSize) << std::endl;

  char character;

  int column = 0;
  int row = 0;
  std::vector<std::vector<std::string>> hashTable(std::ceil(rowSize), std::vector<std::string>(n));

  while (inputFile.get(character))
  {
    if (character == ' ')
      character = '[';

    if (character == '\n')
      character = '-';

    hashTable[row][column] = character;
    column++;

    if (column == n)
    {
      column = 0;
      row++;
    }
  }

  for (int i = 0; i < std::ceil(rowSize); i++)
  {
    std::cout << "Row " << i << ": ";
    for (int j = 0; j < n; j++)
    {
      if (hashTable[i][j].empty())
        hashTable[i][j] = n;

      if (hashTable[i][j] == "[")
        hashTable[i][j] = 32;

      if (hashTable[i][j] == "-")
        hashTable[i][j] = 10;

      std::cout << static_cast<int>(hashTable[i][j][0]) << " ";
    }
    std::cout << std::endl;
  }

  std::vector<int> hashValues(n);
  column = 0;
  row = 0;
  while (column < n)
  {
    if (hashTable[row][column].empty())
      hashValues[column] += n;
    else
      hashValues[column] += static_cast<int>(hashTable[row][column][0]);
    row++;

    if (row == std::ceil(rowSize))
    {
      hashValues[column] = hashValues[column] % 256;
      row = 0;
      column++;
    }
  }

  std::cout << "\nHash values: ";
  for (int i = 0; i < n; i++)
    std::cout << hashValues[i] << " ";

  // Transform the hash values to hexadecimal
  std::vector<std::stringstream> hexHashValues(n);
  for (int i = 0; i < n; i++)
    hexHashValues[i] << std::hex << std::setfill('0') << std::setw(2) << hashValues[i];

  std::cout << "\nHash values: ";
  int resSize = n / 4;
  int counter = 1;
  for (int i = 0; i < n; i++)
  {

    std::cout << hexHashValues[i].str();
    if (counter == resSize)
    {
      std::cout << " ";
      counter = 0;
    }
    counter++;
  }

  // Close file
  inputFile.close();

  return 0;
}