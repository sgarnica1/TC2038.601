/**
 * @file maze_solver.h
 * @author Carlos Salguero
 * @author Sergio Garnica
 * @author Alejandra Cabrera
 * @brief Declaration of the MazeSolver class
 * @version 0.1
 * @date 2023-09-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MAZE_SOLVER_H
#define MAZE_SOLVER_H

// C++ Standard Library
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <optional>
#include <string>

// Using
using Maze = std::vector<std::vector<int>>;
using Visited = std::vector<std::vector<std::int8_t>>;
using MazeSolution = std::unordered_map<int, std::pair<int, int>>;

/**
 * @class MazeSolver
 * @brief Class that solves a maze with backtracking
 */
class MazeSolver
{
public:
    // Constructor
    MazeSolver() = delete;
    MazeSolver(const Maze &);

    // Methods
    bool solve_maze() const;
    std::string to_string() const noexcept;

private:
    const Maze &m_maze;
    mutable Visited m_visited;
    mutable MazeSolution m_solutions;
    int m_rows, m_cols;

    // Methods
    inline bool is_safe(const int &, const int &) const noexcept;
    bool solve_maze_until(const int &, const int &) const noexcept;
};

#endif //! MAZE_SOLVER_H
