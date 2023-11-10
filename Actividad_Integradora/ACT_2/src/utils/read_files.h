/**
 * @file read_files.h
 * @author Alejandra Cabrera
 * @author Carlos Salguero
 * @author Sergio Garnica
 * @brief Reads the files and stores the data in the graph
 * @version 0.1
 * @date 2023-11-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include <sstream>
#include <fstream>
#include <optional>
#include <filesystem>
#include <iostream>
#include <vector>

// Project Files
#include "../graph/graph.h"
#include "logger/logger.h"

/**
 * @brief Reads the files and stores the data in the graph
 *
 * This function opens the specified file, reads the adjacency matrix
 * representing the graph, and constructs a Graph object with the read data.
 * The file should be formatted with the number of vertices followed by the
 * adjacency matrix. Each entry in the adjacency matrix represents the distance
 * between two vertices. Zeroes are expected for non-adjacent vertices or
 * self-loops
 *
 * @param[in] filepath The filesystem path to the file containing
 *                     the graph data.
 * @return std::optional<std::pair<Graph, Graph>> An optional containing the constructed Graph
 *         object if the file was read successfully, or std::nullopt if the
 *         file could not be read or parsed.
 *
 * @note Time complexity: O(V^2) where V is the number of vertices
 * @note Space complexity: O(V^2) where V is the number of vertices
 */
[[nodiscard]] std::optional<std::pair<Graph, Graph>>
readGraphFromFile(const std::filesystem::path &filepath)
{
  std::ifstream file(filepath, std::ios::in | std::ios::binary);
  if (!file.is_open())
  {
    LOG_ERROR("Error opening file: " + filepath.string());
    return std::nullopt;
  }

  if (file.peek() == std::ifstream::traits_type::eof())
  {
    LOG_ERROR("Error parsing file: " + filepath.string());
    return std::nullopt;
  }

  std::stringstream ss;
  ss << file.rdbuf();

  int numVertices;
  ss >> numVertices;

  Graph graph1(numVertices);
  Graph graph2(numVertices);

  for (int i = 0; i < numVertices; ++i)
  {
    for (int j = 0; j < numVertices; ++j)
    {
      int distance;
      if (!(ss >> distance))
      {
        LOG_ERROR("Error parsing file: " + filepath.string());
        return std::nullopt;
      }

      if (i != j)
        graph1.addEdge(i, j, distance);
    }
  }

  for (int i = 0; i < numVertices; ++i)
  {
    for (int j = 0; j < numVertices; ++j)
    {
      int distance;
      if (!(ss >> distance))
      {
        LOG_ERROR("Error parsing file: " + filepath.string());
        return std::nullopt;
      }

      if (i != j)
        graph2.addEdge(i, j, distance);
    }
  }

  return std::make_pair(graph1, graph2);
}