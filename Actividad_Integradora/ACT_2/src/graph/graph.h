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

  std::string findOptimalCabling();
  std::string printOptimalCabling(const std::vector<int> &parent);
  std::string findShortestRoute();
  std::string printShortestRoute(const std::vector<int> &route, int distance);
  std::string findMaxFlow();
  std::string printMaxFlow(int maxFlow, int source, int sink);
  std::string printAdjacencyMatrix();
  int getNumVertices() const;
  int getEdgeWeight(int from, int to) const;

private:
  int numVertices;
  int maxFlow;
  std::vector<std::vector<int>> adjacencyMatrix;
  std::vector<std::vector<int>> transmissionCapacities;

  bool bfs(int source, int sink, std::vector<int> &parent);
};

#endif