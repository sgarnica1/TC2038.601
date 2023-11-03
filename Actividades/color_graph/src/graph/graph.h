/**
 * @file graph.h
 * @author Alejandra Cabrera
 * @author Carlos Salguero
 * @author Sergio Garnica
 * @brief Header file for the Graph class with color graph algorithm
 * @version 0.1
 * @date 2023-11-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <optional>
#include <string>

constexpr char COLOR_RESET[] = "\x1b[0m";
constexpr char COLOR_RED[] = "\x1b[31m";
constexpr char COLOR_GREEN[] = "\x1b[32m";
constexpr char COLOR_YELLOW[] = "\x1b[33m";
constexpr char COLOR_BLUE[] = "\x1b[34m";
constexpr char COLOR_MAGENTA[] = "\x1b[35m";
constexpr char COLOR_CYAN[] = "\x1b[36m";

const std::vector<const char *> terminal_colors = {
    COLOR_RED,
    COLOR_GREEN,
    COLOR_YELLOW,
    COLOR_BLUE,
    COLOR_MAGENTA,
    COLOR_CYAN};

/**
 * @class Graph
 * @brief Represents a graph
 */
class Graph
{
public:
    // Constructor
    explicit Graph(const std::int32_t &vertices);

    // Methods
    void add_edge(const std::int32_t &src, const std::int32_t &dest);
    std::optional<std::string> color_graph();
    std::string print_solution();

private:
    const std::int32_t m_vertices;
    std::vector<std::vector<std::int32_t>> m_adjacency_list;
    std::vector<std::int32_t> m_color_assigned;
};

#endif //! GRAPH_H