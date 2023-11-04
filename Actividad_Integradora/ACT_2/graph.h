#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

class Graph
{
public:
  Graph(int numVertices);
  ~Graph();

  void addEdge(int from, int to, int weight);

  // Métodos relacionados con la primera tarea
  void findOptimalCabling();
  void printOptimalCabling();

  // Métodos relacionados con la segunda tarea
  void findShortestRoute();
  void printShortestRoute();

  // Métodos relacionados con la tercera tarea
  void setTransmissionCapacities(std::vector<std::vector<int>> &capacities);
  int findMaxFlow(int source, int sink);
  void printMaxFlow();

  void printAdjacencyMatrix();

private:
  int numVertices;
  std::vector<std::vector<int>> adjacencyMatrix;
  std::vector<std::vector<int>> transmissionCapacities;
};

#endif