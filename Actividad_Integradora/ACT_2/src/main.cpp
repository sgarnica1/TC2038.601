#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <filesystem>

#include "graph/graph.h"
#include "utils/read_files.h"
#include "utils/knn.h"
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

  auto graphs = readGraphFromFile(argv[1]);
  if (!graphs.has_value())
  {
    LOG_ERROR("Error reading graph from file");
    return EXIT_FAILURE;
  }

  // Write to output file
  std::ofstream output_file("outputs/Equipo_01_Salida_1.txt");
  if (!output_file.is_open())
  {
    LOG_ERROR("Error opening output file");
    return EXIT_FAILURE;
  }

  // Find optimal caling
  output_file << std::get<0>(graphs.value()).findOptimalCabling();

  // Find shortest route
  output_file << std::get<0>(graphs.value()).findShortestRoute();

  // Find max flow
  output_file << std::get<1>(graphs.value()).findMaxFlow();

  // Find central
  std::vector<std::pair<int, int>> centrals = std::get<2>(graphs.value());
  std::pair<int, int> house = centrals.back();
  centrals.pop_back();

  output_file << knn(centrals, house);

  return EXIT_SUCCESS;
}