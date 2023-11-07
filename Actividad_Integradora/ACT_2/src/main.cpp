#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <filesystem>

#include "graph/graph.h"
#include "utils/read_files.h"
#include "utils/logger/logger.h"

/**
 * @struct central
 * @brief Struct for storing the coordinates of a central
 */
struct central
{
  int x, y;
};

/**
 * @brief Entry point of the program
 *
 * @param[in] argc Number of command line arguments
 * @param[in] argv Command line arguments
 *
 * @return int Exit status
 */
int main(int argc, char **argv)
{
  Logger::getInstance()
      .setLogLevel(Logger::Level::INFO)
      .setConsoleOutput(true)
      .setFileOutput(true);

  if (argc != 2)
  {
    LOG_ERROR("Usage: ./main <input_file>");
    return EXIT_FAILURE;
  }

  auto graph = readGraphFromFile(argv[1]);
  if (!graph.has_value())
  {
    LOG_ERROR("Error reading graph from file");
    return EXIT_FAILURE;
  }

  graph.value().findOptimalCabling();
  return EXIT_SUCCESS;
}