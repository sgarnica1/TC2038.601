#include <stdexcept>
#include <sstream>
#include <algorithm>

#include "graph.h"

// Constructor
/**
 * @brief Construct a new Graph:: Graph object
 * @param[in] vertices Number of vertices in the graph
 */
Graph::Graph(const std::int32_t &vertices)
    : m_vertices(vertices)
{
  m_adjacency_list.resize(m_vertices);
  m_color_assigned.resize(m_vertices);

  m_color_assigned.reserve(m_vertices);
}

// Methods
/**
 * @brief Adds an edge to the graph
 * @param[in] vertex Source vertex
 * @param[in] weight Destination vertex
 * @throw std::out_of_range if vertex is out of range
 */
void Graph::add_edge(const std::int32_t &vertex, const std::int32_t &weight)
{
  if (vertex >= m_vertices || weight >= m_vertices)
    throw std::out_of_range("Vertex is out of range");

  m_adjacency_list[vertex].emplace_back(weight);
  m_adjacency_list[weight].emplace_back(vertex);
}

/**
 * @brief Colors the graph
 * @details This function colors the graph using the greedy algorithm
 * @return std::optional<std::string> Returns the solution if it exists
 * @timecomplexity O(N^2)
 */
std::optional<std::string> Graph::color_graph()
{
  m_color_assigned.assign(m_vertices, -1);
  m_color_assigned[0] = 0;

  for (int u = 1; u < m_vertices; u++)
  {
    std::vector<bool> available(m_vertices, true);

    for (int v : m_adjacency_list[u])
      if (m_color_assigned[v] != -1)
        available[m_color_assigned[v]] = false;

    int color;
    for (color = 0; color < m_vertices; color++)
      if (available[color])
        break;

    if (color == m_vertices)
      return "No es posible  asignar colores a los nodos";

    m_color_assigned[u] = color;
  }

  return std::nullopt;
}

/**
 * @brief Prints the solution
 * @return std::string Returns the solution
 */
std::string Graph::print_solution()
{
  std::stringstream ss;
  auto result = color_graph();

  if (result.has_value())
    ss << "Error: " << result.value() << std::endl;

  else
  {
    ss << "Graph" << std::endl;
    ss << "-------------------------" << std::endl;

    for (int i = 0; i < m_vertices; i++)
    {
      ss << i << " --> ";
      for (int v : m_adjacency_list[i])
        ss << v << " ";
      ss << std::endl;
    }

    ss << "\nGraph Coloring Solution:" << std::endl;
    ss << "-------------------------" << std::endl;

    for (int u = 0; u < m_vertices; u++)
    {
      int color_index = m_color_assigned[u] % terminal_colors.size();
      const char *color_code = terminal_colors[color_index];

      ss << "Vertex " << u << " --> Color Code: "
         << color_code << " (" << terminal_colors[color_index] << ")"
         << COLOR_RESET << std::endl;
    }

    ss << "-------------------------" << std::endl;

    int max_color_index = *std::max_element(
        m_color_assigned.begin(), m_color_assigned.end());

    ss << "Number of colors used: " << max_color_index + 1 << std::endl;
  }

  return ss.str();
}