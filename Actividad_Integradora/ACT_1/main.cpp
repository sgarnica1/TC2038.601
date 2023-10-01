#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <filesystem>

#include "kmp.h"
#include "longest_common_substring.h"
#include "utils.h"

namespace fs = std::filesystem;

// Constants
const std::string TRANSMISSION_DIRECTORY = "input/transmission";
const std::string MCODE_DIRECTORY = "input/mcode";

int main(int argc, char **argv)
{
  print_transmission_files_label();
  std::vector<std::string> transmission_files = get_files_content(TRANSMISSION_DIRECTORY);

  print_mcode_files_label();
  std::vector<std::string> mcode_files = get_files_content(MCODE_DIRECTORY);

  // Search for mcode in transmission files
  print_search_result_label();
  int transmission_index = 0;
  int mcode_index = 0;
  for (const auto &file : transmission_files)
  {
    print_transmission_file_label(++transmission_index);
    for (const auto &mcode : mcode_files)
    {
      std::cout << "mcode " << ++mcode_index << "\n";
      KMPSearch(const_cast<char *>(mcode.c_str()), const_cast<char *>(file.c_str()));
      std::cout << std::endl;
    }
    mcode_index = 0;
    std::cout << std::endl;
  }

  // Longest substring
  print_longest_substring_label();
  std::string longest_substring = longest_common_substring(transmission_files[0], transmission_files[1]);
  print_longest_substring(longest_substring);

  transmission_index = 0;
  for (const auto &file : transmission_files)
  {
    std::cout << "Posiciones en la transmision" << ++transmission_index << ":\n";
    KMPSearch(const_cast<char *>(longest_substring.c_str()), const_cast<char *>(file.c_str()));
    std::cout << std::endl;
  }

  return 0;
}