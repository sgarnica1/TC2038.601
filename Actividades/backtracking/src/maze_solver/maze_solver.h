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
#include <unordered_map>
#include <optional>
#include <string>

/**
 * @class MazeSolver
 * @brief Class that solves a maze with backtracking
 */
class MazeSolver
{
public:
    // Constructor
    MazeSolver() = delete;
    MazeSolver(const std::vector<std::vector<int>> &,
               const int &, const int &);

    // Methods
    bool solve_maze();
    std::string to_string() const noexcept;

private:
    std::vector<std::vector<int>> m_maze;
    std::unordered_map<int, std::pair<int, int>> m_solutions;
    int m_rows, m_cols;

    // Methods
    bool is_safe(const int &, const int &);
    bool solve_maze_until(const int &, const int &);
};

#endif //! MAZE_SOLVER_H