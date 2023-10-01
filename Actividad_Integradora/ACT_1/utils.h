/**
 * @file utils.h
 * @brief Header file containing the function prototypes for the main.cpp file
 */

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <algorithm>

// Function definitions
// Auxiliar functions
/**
 * @brief
 * Gets the filename from the arguments passed to the program
 * @param filename - Filename passed to the program
 * @return std::vector<std::filesystem::path> - Vector of filenames
 */
std::vector<std::filesystem::path> get_filenames(
    const std::string_view &input_directory)
{
  std::vector<std::filesystem::path> filenames;
  std::filesystem::path path{input_directory};

  if (!std::filesystem::is_directory(path))
  {
    std::cerr << "Error: " << input_directory << " is not a valid directory" << std::endl;
    exit(1);
  }

  for (const auto &entry : std::filesystem::directory_iterator(path))
  {
    if (entry.path().extension() == ".txt")
    {
      filenames.push_back(entry.path());
    }
  }

  if (filenames.empty())
  {
    std::cerr << "Error: no input files found in " << input_directory << std::endl;
    exit(1);
  }

  return filenames;
}

/**
 * @brief
 * Gets the mcode memory array from the mcode files
 * @param files_directory - Directory containing the mcode files
 * @return std::vector<std::string> - Vector of strings containing the mcode memory
 */
std::vector<std::string> get_files_content(std::string directory)
{
  auto files = get_filenames(directory);
  std::vector<std::string> file_memory;
  for (const auto &file : files)
  {
    std::string filename = file.filename().string();
    std::cout << "ARCHIVO: " << filename << std::endl;

    std::ifstream read_file(file);
    if (read_file.is_open())
    {
      std::string file_content((std::istreambuf_iterator<char>(read_file)), std::istreambuf_iterator<char>());
      file_memory.push_back(file_content.c_str());

      // Print file content
      if (file_content.size() > 20)
        std::cout << "CONTENIDO: \n"
                  << file_content << "\n\n";
      else
        std::cout << "CONTENIDO: " << file_content << "\n\n";
    }
    else
    {
      std::cerr << "Error: No se pudo abrir el archivo " << filename << std::endl;
      exit(1);
    }
    read_file.close();
  }
  return file_memory;
}

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