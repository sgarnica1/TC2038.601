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
#include <limits>
#include <queue>
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
    adjacencyMatrix[from][to] = weight;

  else
    LOG_ERROR("Attempted to add edge with invalid vertices or weight");
}

/**
 * @brief Constructs the Minimum Spanning Tree (MST) of the graph using
 * Prim's algorithm.
 *
 * @details A minimum spanning tree (MST) is a subset of the edges of a connected,
 * edge-weighted graph that connects all the vertices together without any cycles
 * and with the minimum possible total edge weight. It is a way of finding the most
 * economical way to connect a set of vertices.
 *
 * @details This methods applies Prim's algorithm to find the MST of the graph
 * represented by the adjacency matrix. The MST is a subset of the edges
 * that connects all the vertices together, without any cycles and with
 * the minimum possible total edge weight. This is used to determine
 * the most efficient way to lay out cabling with the least amount of fiber
 * optic cable needed to connect all colonies (nodes).
 *
 * @details The function initializes all key values to infinity and sets the
 * first key to zero to ensure it is picked first. Then, it proceeds to add
 * edges of the MST by picking the smallest weight edge from the set of edges
 * that connect the current MST to vertices not yet included in the MST.
 *
 * @details After the algorithm completes, the `parent` array will represent
 * the MST. The edges of the MST are then logged, showing the connections
 * and their corresponding weights.
 *
 * @note The graph must be connected for Prim's algorithm to find a valid MST.
 * If the graph is not connected, the algorithm will only find a spanning tree
 * for one of the connected components.
 *
 * @note The algorithm runs in O((V + E) log(V)) time, where V is the number
 *       of vertices and E is the number of edges.
 * @note The algorithm runs in O(V) space due to the storage of the `key`,
 *       `parent`, and `inMST` arrays, which all have a size proportional to
 *        the number of vertices
 */
void Graph::findOptimalCabling()
{
  std::priority_queue<std::pair<int, int>,
                      std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      minHeap;

  std::vector<int> key(numVertices, std::numeric_limits<int>::max());
  std::vector<int> parent(numVertices, -1);
  std::vector<bool> inMST(numVertices, false);

  for (int i = 0; i < numVertices; ++i)
  {
    key[i] = std::numeric_limits<int>::max();
    parent[i] = -1;
  }

  for (int i = 0; i < numVertices; ++i)
  {
    if (!inMST[i])
    {
      key[i] = 0;
      minHeap.push(std::make_pair(0, i));

      while (!minHeap.empty())
      {
        int u = minHeap.top().second;
        minHeap.pop();

        if (inMST[u])
          continue;

        inMST[u] = true;

        for (int v = 0; v < numVertices; v++)
        {
          if (adjacencyMatrix[u][v] && !inMST[v] &&
              adjacencyMatrix[u][v] < key[v])
          {
            parent[v] = u;
            key[v] = adjacencyMatrix[u][v];

            minHeap.push(std::make_pair(key[v], v));
          }
        }
      }
    }
  }

  printOptimalCabling(parent);
}

/**
 * @brief Prints a representation of the Minimum Spanning Tree (MST) found
 * using Prim's algorithm. The MST is printed as an adjacency matrix.
 *
 * @param[in] parent Array containing the parent of each vertex
 */
void Graph::printOptimalCabling(const std::vector<int> &parent)
{
  std::ostringstream oss;
  oss << "Minimum Spanning Tree (MST) found using Prim's algorithm:\n";

  for (int i = 0; i < numVertices; i++)
  {
    for (int j = 0; j < numVertices; j++)
    {
      int weight = (j == parent[i] || i == parent[j])
                       ? adjacencyMatrix[i][j]
                       : 0;

      oss << weight << " ";
    }

    oss << std::endl;
  }

  std::cout << oss.str();
}

/**
 * @brief Finds the maximun flow from the first node to the last one.
 *
 * @return int Max flow
 */
int Graph::findMaxFlow()
{
  std::cout << "\nFinding max flow...\n";

  int source = 0;
  int sink = numVertices - 1;
  std::vector<int> parent(numVertices, -1);

  bfs(source, sink, parent);

  // printMaxFlow(source, sink, parent);
  return 1;
}

/**
 * @brief BFS algorithm to find the shortest route from the source to the sink.
 * @param[in] source Source vertex
 * @param[in] sink Destination vertex
 * @param[in] parent Array containing the parent of each vertex
 */

void Graph::bfs(int source, int sink, std::vector<int> &parent)
{
  std::queue<int> q;
  std::vector<int> path;
  std::vector<bool> visited(numVertices, false);
  int maxFlow = 0;
  transmissionCapacities = adjacencyMatrix;
  bool flowFound = true;

  // print transmission capacities
  std::cout << "Transmission capacities: " << std::endl;
  for (int i = 0; i < numVertices; i++)
  {
    for (int j = 0; j < numVertices; j++)
    {
      std::cout << transmissionCapacities[i][j] << " ";
    }
    std::cout << std::endl;
  }

  while (flowFound)
  {
    flowFound = false;
    q.push(source);
    visited[source] = true;

    std::cout << "Here1\n";

    while (q.size() > 0)
    {
      int current = q.front();
      std::cout << "Current: " << current << std::endl;
      q.pop();

      std::cout << "Here2\n";

      for (int i = 0; i < numVertices; i++)
        if (transmissionCapacities[current][i] > 0 && !visited[i])
        {
          std::cout << "Here3\n";
          q.push(i);
          visited[i] = true;
          parent[i] = current;

          if (i == sink)
          {
            flowFound = true;
            break;
          }
        }
    }
    std::cout << "Here4\n";

    // Reconstruct the path by following the parent chain from destination to source
    for (int v = sink; v != source; v = parent[v])
      path.push_back(v);

    // Add the source vertex to the path
    path.push_back(source);

    std::vector<int> capacities;

    // Find the transmission capacities of the edges in the path
    for (auto it = path.rbegin(); it != path.rend(); ++it)
      if (*it != sink)
        capacities.push_back(transmissionCapacities[*it][*(it + 1)]);

    // Find the minimum transmission capacity in the path
    int minCapacity = *std::min_element(capacities.begin(), capacities.end());
    maxFlow += minCapacity;

    // Update the transmission capacities of the edges in the path
    for (auto it = path.rbegin(); it != path.rend(); ++it)
      if (*it != sink)
        transmissionCapacities[*it][*(it + 1)] -= minCapacity;

    // print transmission capacities
    std::cout << "Transmission capacities: " << std::endl;
    for (int i = 0; i < numVertices; i++)
    {
      for (int j = 0; j < numVertices; j++)
      {
        std::cout << transmissionCapacities[i][j] << " ";
      }
      std::cout << std::endl;
    }

    // Clear the path and visited array
    path.clear();
    visited.clear();

    // Reset the visited array
    visited.resize(numVertices, false);
  }

  std::cout << "Max flow: " << maxFlow << std::endl;
}
// /**
//  * @brief BFS algorithm to find the shortest route from the source to the sink.
//  * @param[in] source Source vertex
//  * @param[in] sink Destination vertex
//  * @param[in] parent Array containing the parent of each vertex
//  */

// void Graph::bfs(int source, int sink, std::vector<int> &parent)
// {
//   std::queue<int> q;
//   std::vector<bool> visited(numVertices, false);

//   q.push(source);
//   visited[source] = true;

//   while (q.size() > 0)
//   {
//     int current = q.front();
//     q.pop();

//     for (int i = 0; i < numVertices; i++)
//       if (adjacencyMatrix[current][i] != 0 && !visited[i])
//       {
//         q.push(i);
//         visited[i] = true;
//         parent[i] = current;
//       }
//   }
// }

/**
 * @detils Print Max Flow
 * @param[in] source Source vertex
 * @param[in] sink Destination vertex
 * @param[in] parent Array containing the parent of each vertex
 */

void Graph::printMaxFlow(int source, int sink, std::vector<int> &parent)
{
  std::vector<int> path;

  // Reconstruct the path by following the parent chain from destination to source
  for (int v = sink; v != source; v = parent[v])
    path.push_back(v);

  // Add the source vertex to the path
  path.push_back(source);

  // Print the path in reverse order (from source to destination)
  std::cout << "Shortest Path: ";
  for (auto it = path.rbegin(); it != path.rend(); ++it)
    std::cout << *it << " ";

  std::cout << std::endl;
}