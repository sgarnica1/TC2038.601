#include <iostream>
#include <vector>
#include <limits>
#include <list>

#include "dijkstra.cpp"
#include "floyd.cpp"

typedef std::pair<int, int> pii;

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            std::cin >> matrix[i][j];

    std::vector<std::vector<pii>> graph(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (matrix[i][j] != -1)
                graph[i].push_back({j, matrix[i][j]});

    std::cout << "Dijkstra (All Pairs Shortest Path):" << std::endl;
    auto allPaths = all_pairs_shortest_path(graph);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j)
            {
                auto result = allPaths[i][j];
                std::cout << "node " << (i + 1) << " to node " << (j + 1)
                          << ":  Distance: " << result.first << ", Path: ";

                for (int node : result.second)
                    std::cout << node + 1 << " ";

                std::cout << std::endl;
            }
        }
    }

    std::cout << std::endl
              << "Floyd-Warshall:" << std::endl;

    std::vector<std::vector<int>> pred(n, std::vector<int>(n));
    floydWarshall(matrix, pred);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            std::cout << matrix[i][j] << " ";

        std::cout << std::endl;
    }
}
