/**
 * @file graph.cpp
 * @author Alejandra Cabrera
 * @author Carlos Salguero
 * @author Sergio Garnica
 * @brief Implementation of the Graph class
 * @version 0.1
 * @date 2023-11-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <sstream>

#include "graph.h"
#include "../utils/logger/logger.h"

/**
 * @brief Construct a new Graph:: Graph object
 * @param[in] numVertices Number of vertices in the graph
 */
Graph::Graph(int numVertices) : numVertices(numVertices)
{
  adjacencyMatrix.resize(numVertices,
                         std::vector<int>(numVertices, 0));
  transmissionCapacities.resize(numVertices,
                                std::vector<int>(numVertices, 0));
}

/**
 * @brief Add an edge to the graph
 * @param[in] from Source vertex
 * @param[in] to Destination vertex
 * @param[in] weight Weight of the edge
 */
void Graph::addEdge(int from, int to, int weight)
{
  if (from >= 0 && from < numVertices && to >= 0 && to < numVertices)
  {
    adjacencyMatrix[from][to] = weight;
    LOG_INFO("Edge added from " + std::to_string(from) +
             " to " + std::to_string(to) + " with weight " +
             std::to_string(weight));
  }

  else
  {
    LOG_ERROR("Attempted to add edge with invalid vertices or weight");
  }
}

/**
 * @brief Prints the graph in a string format
 */
void Graph::toString() const
{
  std::stringstream ss;

  ss << "Graph generated from file: " << std::endl;

  for (int i = 0; i < numVertices; i++)
  {
    for (int j = 0; j < numVertices; j++)
      ss << adjacencyMatrix[i][j] << " ";

    ss << std::endl;
  }

  LOG_INFO(ss.str());
}