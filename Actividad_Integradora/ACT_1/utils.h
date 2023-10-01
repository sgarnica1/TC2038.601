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
    const std::vector<std::string> &filenames_to_search,
    const std::string_view &input_directory)
{
  std::vector<std::filesystem::path> found_filenames;
  std::filesystem::path path{input_directory};

  if (!std::filesystem::is_directory(path))
  {
    std::cerr << "Error: " << input_directory << " is not a valid directory" << std::endl;
    exit(1);
  }

  for (const std::string &filename : filenames_to_search)
  {
    std::filesystem::path filepath = path / filename;
    found_filenames.push_back(filepath);
  }

  if (found_filenames.empty())
  {
    std::cerr << "Error: No valid input files found in " << input_directory << std::endl;
    exit(1);
  }

  return found_filenames;
}
/**
 * @brief
 * Gets the mcode memory array from the mcode files
 * @param files_directory - Directory containing the mcode files
 * @return std::vector<std::string> - Vector of strings containing the mcode memory
 */
std::vector<std::string> get_files_content(const std::vector<std::string> &filenames_to_search,
                                           const std::string_view &input_directory)
{
  auto files = get_filenames(filenames_to_search, input_directory);
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
      file_memory.push_back("NOT_FOUND");
      std::cerr << "No se encontro el archivo\n\n";
    }

    read_file.close();
  }
  return file_memory;
}

/**
 * @brief
 * Reverse a string
 * @param str - String to reverse
 * @return std::string - Reversed string
 */
std::string reverse_string(std::string str)
{
  std::reverse(str.begin(), str.end());
  return str;
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
 * Print search result label
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
 * Print reversed search result label
 * @return void
 */
void print_reversed_search_result_label()
{
  std::cout << "\n=================================================================================\n"
            << " RESULTADOS DE BUSQUEDA DE CODIGO MALICIOSO ESPEJEADO EN ARCHIVOS DE TRANSMISION\n"
            << "=================================================================================\n\n";
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
void print_transmission_file_label(std::string filename)
{
  std::cout << "\nT R A N S M I S S I O N: " << filename << "\n\n";
}

/**
 * @brief
 * Print longest substring position
 * @param index - mcode file index
 * @return void
 */
void print_longest_substring_position(int index)
{
  std::cout << "Posiciones en la transmision" << index << ":\n";
}

/**
 * @brief
 * Print mcode file lable
 * @param index - mcode file index
 * @return void
 */
void print_mcode_file_label(std::string filename)
{
  std::cout << "mcode " << filename << "\n";
}

#endif // UTILS_H