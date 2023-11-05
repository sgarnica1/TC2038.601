/**
 * @file graph.h
 * @author Alejandra Cabrera
 * @author Carlos Salguero
 * @author Sergio Garnica
 * @brief Declaration of the Graph class
 * @version 0.1
 * @date 2023-11-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

/**
 * @class Graph
 * @brief Represents a graph
 */
class Graph
{
public:
  // Constructor
  Graph(int numVertices);

  // Destructor
  ~Graph() = default;

  // Methods
  void addEdge(int from, int to, int weight);

  void findOptimalCabling();
  void printOptimalCabling();
  void findShortestRoute();
  void printShortestRoute();
  void setTransmissionCapacities(std::vector<std::vector<int>> &capacities);
  int findMaxFlow(int source, int sink);
  void printMaxFlow();
  void printAdjacencyMatrix();
  void toString() const;

private:
  int numVertices;
  std::vector<std::vector<int>> adjacencyMatrix;
  std::vector<std::vector<int>> transmissionCapacities;
};

#endif