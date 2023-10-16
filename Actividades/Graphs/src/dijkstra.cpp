#include <vector>
#include <limits>
#include <queue>

typedef std::pair<int, int> pii;

std::vector<int> dijkstra(const std::vector<std::vector<pii>> &graph, int start)
{
    std::size_t n{graph.size()};
    std::vector<int> distance(n, std::numeric_limits<int>::max());
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;

    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int u{pq.top().second};
        pq.pop();

        for (auto &edge : graph[u])
        {
            int v{edge.first};
            int w{edge.second};

            if (distance[v] > distance[u] + w)
            {
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}