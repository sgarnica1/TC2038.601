/**
 * @file hash_string.h
 * @author Sergio Garnica
 * @author Carlos Salguero
 * @author Alejandra Cabrera
 * @brief Hash string implementation to hash a string file
 * @version 0.1
 * @date 2023-09-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef HASH_STRING_H
#define HASH_STRING_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

/**
 * @brief
 * Computes the algorithm to hash a string file
 * @param inputFile The file to be hashed
 * @param n The number of columns for the matrix
 * @return std::vector<std::stringstream> The hashed file
 * @time_complexity O(n) where n is the columns x rows of the hash matrix determined by the file size
 * @space_complexity O(n) where n is the columns x rows of the hash matrix determined by the file size
 */
std::vector<std::stringstream> hash_string(std::ifstream &inputFile, int n)
{

  int column = 0, row = 0, fileLength = 0;
  int resSize = n / 4, counter = 1;
  double rowSize = 0;
  int rowSizeInt = 0;
  char character;

  // Determine the length of the file
  inputFile.seekg(0, std::ios::end);
  fileLength = inputFile.tellg();
  inputFile.seekg(0, std::ios::beg);

  // Calculate the desired column size
  rowSize = static_cast<double>(fileLength) / static_cast<double>(n);
  rowSizeInt = std::ceil(rowSize);

  // Matrix and vector to store the file
  std::vector<std::vector<std::string>> hashTable(rowSizeInt, std::vector<std::string>(n)); // Matrix to store the file
  std::vector<int> hashValues(n);

  // Store the file in the matrix
  std::cout << "Matriz generada con el algoritmo, los satlos de línea se representan con '-' y los espacios con '['\n";
  for (int i = 0; i < (n * rowSizeInt); i++)
  {
    inputFile.get(character);

    if (character == '\n')
    {
      hashTable[row][column] = '-';
      fileLength--;
    }
    else if (i >= fileLength)
      hashTable[row][column] = '[';
    else
      hashTable[row][column] = character;

    std::cout << hashTable[row][column] << " ";
    column++;

    if (column == n)
    {
      std::cout << "\n";
      column = 0;
      row++;
    }
  }

  // Compute the hash values
  column = 0;
  row = 0;
  while (column < n)
  {
    if (hashTable[row][column] == "[")
      hashTable[row][column][0] = n;

    if (hashTable[row][column] == "-")
      hashTable[row][column][0] = 10;

    hashValues[column] += static_cast<int>(hashTable[row][column][0]);
    row++;

    if (row == rowSizeInt)
    {
      hashValues[column] = hashValues[column] % 256;
      row = 0;
      column++;
    }
  }

  // Print the hash values
  std::cout << "\nArreglo de longitud 'n' que muestra la suma de las columnas con el modulo 256\n";
  for (int i = 0; i < n; i++)
    std::cout << hashValues[i] << " ";

  // Transform the hash values to hexadecimal
  std::vector<std::stringstream> hexHashValues(n);
  for (int i = 0; i < n; i++)
    hexHashValues[i] << std::hex << std::setfill('0') << std::setw(2) << hashValues[i];

  // Print the hexadecimal values
  std::cout << "\n\nRepresentacion hexadecimal\n";
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

  return hexHashValues;
}

#endif //! HASH_STRING_H