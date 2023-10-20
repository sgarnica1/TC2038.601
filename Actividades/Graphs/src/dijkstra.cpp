/**
 * @file dijkstra.cpp
 * @author Alejandra Cabrera
 * @author Carlos Salguero
 * @author Sergio Garnica
 * @brief Dijsktra's algorithm implementation for shortest path
 * @version 0.1
 * @date 2023-10-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <vector>
#include <limits>
#include <queue>
#include <set>
#include <list>
#include <stdexcept>

typedef std::pair<int, int> pii;
typedef std::vector<std::pair<int, std::list<int>>> repeated;

/**
 * @brief Implements Dijkstra's algorithm for finding the shortest path
 * between nodes in a graph.
 *
 * The custom comparator `comp` is used to order the nodes in the priority queue
 * based on their current shortest distance from the start node. This ensures
 * that the node with the shortest distance is always at the top of the queue.
 *
 * @param[in] graph Adjacency list representation of the graph.
 * @param[in] start Starting Node.
 * @param[in] target Target Node.
 * @return A pair containing the shortest distance and the shortest path
 *         from start to target.
 * @throws std::runtime_error If the graph is empty.
 * @throws std::runtime_error If the start or target node is not in the graph.
 * @throws std::runtime_error If a negative edge weight is found.
 *
 * @note Time complexity: O(E log(V)) where E is the number of edges and
 *       V is the number of vertices.
 * @note Space complexity: O(2V) which simplifies to O(V). This accounts
 *       for the distance and predecessor vectors, and the priority queue.
 */
std::pair<int, std::list<int>> dijkstra(
    const std::vector<std::vector<pii>> &graph, int start, int target)
{
    if (graph.empty())
        throw std::runtime_error("Graph is empty");

    std::size_t n = graph.size();

    if (start < 0 || start >= n || target < 0 || target >= n)
        throw std::runtime_error("Invalid node");

    std::vector<int> distance(n, std::numeric_limits<int>::max());
    std::vector<int> predecessor(n, -1);

    auto comp = [&distance](int a, int b)
    { return distance[a] > distance[b]; };

    std::priority_queue<int, std::vector<int>, decltype(comp)> queue(comp);

    distance[start] = 0;
    queue.push(start);

    while (!queue.empty())
    {
        int u = queue.top();
        queue.pop();

        if (u == target)
            break;

        for (auto &edge : graph[u])
        {
            int v = edge.first;
            int w = edge.second;

            if (w < 0)
                throw std::runtime_error("Negative edge weight");

            if (distance[v] > distance[u] + w)
            {
                distance[v] = distance[u] + w;
                predecessor[v] = u;

                queue.push(v);
            }
        }
    }

    std::list<int> path;
    for (int at = target; at != -1; at = predecessor[at])
        path.push_front(at);

    if (path.front() != start)
        path.clear();

    return {distance[target], path};
}

/**
 * @brief Computes the shortest path between all pairs of nodes using
 *        Dijkstra's algorithm. Calculates the shortest path between every
 *        pair of nodes in the graph and stores the results in a matrix.
 *
 * @param[in] graph Adjacency list representation of the graph. Each pair
 *                  in the list represents a node and its weight.
 * @return std::vector<repeated> Matrix containing the shortest distance and
 *         path for every pair of nodes. The matrix is size NxN where N is the
 *         number of nodes in the graph. Each entry (i, j) contains a pair
 *         representing the shortest distance from node i to node j
 *         and the path taken
 *
 * @note Time Complexity: o(N^2 * (e log(V))) where N is the number of nodes,
 *       E is the number of edges, and V is the number of vertices. Since it is
 *       running Dijkstra's algorithm for every pair of nodes.
 * @note Space complexity: o(N^2) for the resulting matrix.
 */
std::vector<repeated> all_pairs_shortest_path(
    const std::vector<std::vector<pii>> &graph)
{
    std::size_t n{graph.size()};
    std::vector<repeated> all_paths(n, repeated(n));

    for (int i{}; i < n; ++i)
        for (int j{}; j < n; ++j)
        {
            if (i != j)
                all_paths[i][j] = dijkstra(graph, i, j);

            else
                all_paths[i][j] = {0, {i}};
        }

    return all_paths;
}