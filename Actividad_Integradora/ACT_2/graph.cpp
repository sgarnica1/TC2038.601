#include "graph.h"

/**
 * @brief Construct a new Graph:: Graph object
 * @param numVertices int
*/
Graph::Graph(int numVertices) : numVertices(numVertices)
{
  adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
  transmissionCapacities.resize(numVertices, std::vector<int>(numVertices, 0));
}

Graph::~Graph()
{
  // Destructor
}

void Graph::addEdge(int from, int to, int weight)
{
  if (from >= 0 && from < numVertices && to >= 0 && to < numVertices)
  {
    adjacencyMatrix[from][to] = weight;
  }
}
