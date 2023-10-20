#include <vector>
#include <limits>
#include <iostream>
#include <list>

typedef std::pair<int, std::list<int>> PathInfo;

/**
 * @brief Computes the shortest paths between all pairs of nodes
 *        using the Floyd-Warshall algorithm.
 *
 * @param[in,out] dist Matrix representing the shortest distances between nodes.
 * @param[out] pred Matrix used for path reconstruction.
 *
 * @note Time complexity: O(V^3) where V is the number of vertices.
 * @note Space complexity: O(V^2) for the distance and predecessor matrices.
 */
void floydWarshall(std::vector<std::vector<int>> &dist,
                   std::vector<std::vector<int>> &pred)
{
    int n = dist.size();

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (dist[i][j] == -1)
                dist[i][j] = std::numeric_limits<int>::max();

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (dist[i][j] != std::numeric_limits<int>::max() && i != j)
                pred[i][j] = i;

            else
                pred[i][j] = -1;
        }
    }

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dist[i][k] != std::numeric_limits<int>::max() &&
                    dist[k][j] != std::numeric_limits<int>::max() &&
                    dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = pred[k][j];
                }
            }
        }
    }
}