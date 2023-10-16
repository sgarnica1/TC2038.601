#include <iostream>
#include <vector>
#include <limits>

// Project files
#include "dijkstra.cpp"
#include "floyd.cpp"

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<std::vector<pii>> graph(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (matrix[i][j] != -1)
                graph[i].push_back({j, matrix[i][j]});

    std::cout << "Dijkstra:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::vector<int> distances = dijkstra(graph, i);

        for (int j = 0; j < n; ++j)
            if (i != j)
                std::cout << "node " << (i + 1) << " to node "
                          << (j + 1) << ":  " << distances[j] << std::endl;
    }

    std::cout << std::endl
              << "Floyd:" << std::endl;
    floyd(matrix);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
}