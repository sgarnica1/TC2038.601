#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <filesystem>

#include "kmp.h"

namespace fs = std::filesystem;

// Function prototypes
std::vector<std::filesystem::path> get_filenames(const std::string_view &);
std::vector<std::string> get_files_content(std::string directory);

int main(int argc, char **argv)
{
  std::vector<std::string> transmission_files = get_files_content("transmission");
  std::vector<std::string> mcode_files = get_files_content("mcode");

  for (const auto &file : transmission_files)
    for (const auto &mcode : mcode_files)
      KMPSearch(const_cast<char *>(mcode.c_str()), const_cast<char *>(file.c_str()));

  return 0;
}

// Function definitions
// Auxiliar functions
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
    std::cout << "[ARCHIVO]: " << filename << std::endl;

    std::ifstream read_file(file);
    if (read_file.is_open())
    {
      std::string file_content((std::istreambuf_iterator<char>(read_file)), std::istreambuf_iterator<char>());
      file_memory.push_back(file_content.c_str());

      // Print file content
      if (file_content.size() > 20)
        std::cout << "[CONTENIDO]: \n"
                  << file_content << "\n\n";
      else
        std::cout << "[CONTENIDO]: " << file_content << "\n\n";
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