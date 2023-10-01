/**
 * @file utils.h
 * @brief Header file containing the function prototypes for the main.cpp file
 */

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <algorithm>

/**
 * @brief
 * Print transmission files label
 * @return void
 */
void print_transmission_files_label()
{
  std::cout << "=====================================================\n"
            << " ARCHIVOS DE TRANSMISION\n"
            << "=====================================================\n\n";
}

/**
 * @brief
 * Print mcode files label
 * @return void
 */
void print_mcode_files_label()
{
  std::cout << "=====================================================\n"
            << " ARCHIVOS DE CODIGO MALICIOSO\n"
            << "=====================================================\n\n";
}

/**
 * @brief
 * Print searcc result label
 * @return void
 */
void print_search_result_label()
{
  std::cout << "\n=======================================================================\n"
            << " RESULTADOS DE BUSQUEDA DE CODIGO MALICIOSO EN ARCHIVOS DE TRANSMISION\n"
            << "=======================================================================\n\n";
}

/**
 * @brief
 * Print longest substring label
 * @return void
 */
void print_longest_substring_label()
{
  std::cout << "\n=====================================================\n"
            << " SUBSTRING MAS LARGO ENTRE ARCHIVOS DE TRANMISION\n"
            << "=====================================================\n";
}

/**
 * @brief
 * Print longest substring
 * @param str - subtring
 * @return void
 */
void print_longest_substring(std::string str)
{
  if (str.empty())
    std::cout << "No se encontro un subtring compartido en ambas transmisiones";
  else
    std::cout << "Sub-String mas largo: " << str;
  std::cout << "\n";
}

/**
 * @brief
 * Print transmission file label
 * @param index - transmission file index
 * @return void
 */
void print_transmission_file_label(int index)
{
  std::cout << "\nT R A N S M I S S I O N: " << index << "\n\n";
}

#endif // UTILS_H