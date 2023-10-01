#ifndef LONGEST_COMMON_SUBSTRING_H
#define LONGEST_COMMON_SUBSTRING_H

#include <iostream>
#include <string>
#include <vector>

std::string longest_common_substring(std::string str1, std::string str2)
{
  int length_str1 = str1.length();
  int length_str2 = str2.length();

  // Crear una matriz para almacenar la longitud de la subcadena común
  std::vector<std::vector<int>> dp(length_str1 + 1, std::vector<int>(length_str2 + 1, 0));

  int maxLength = 0; // Longitud de la subcadena común más larga
  int endIndex = 0;  // Índice final de la subcadena común

  // Llenar la matriz dp
  for (int row = 1; row <= length_str1; ++row)
    for (int column = 1; column <= length_str2; ++column)
      if (str1[row - 1] == str2[column - 1])
      {
        dp[row][column] = dp[row - 1][column - 1] + 1;
        if (dp[row][column] > maxLength)
        {
          maxLength = dp[row][column];
          endIndex = row - 1; // Actualizar el índice final
        }
      }

  // Construir y devolver la subcadena común más larga
  if (maxLength == 0 || (str1 == "NOT_FOUND" && str2 == "NOT_FOUND"))
    return ""; // No hay subcadena común
  else
    return str1.substr(endIndex - maxLength + 1, maxLength);
}

#endif // LONGEST_COMMON_SUBSTRING_H