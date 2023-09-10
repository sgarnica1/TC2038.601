/**
 * @file maze_solver.h
 * @author Carlos Salguero
 * @author Sergio Garnica
 * @author Alejandra Cabrera
 * @brief Implementation of the MazeSolver class
 * @version 0.1
 * @date 2023-09-02
 *
 * @copyright Copyright (c) 2023
 *
 */
// C++ Standard Library
#include <array>

// Project files
#include "maze_solver.h"

// Constructor
/**
 * @brief
 * Construct a new Maze Solver:: Maze Solver object
 * @param maze Maze to solve
 * @param rows Number of rows of the maze
 * @param cols Number of columns of the maze
 */
MazeSolver::MazeSolver(const Maze &maze) : m_maze{maze}
{
    m_rows = static_cast<int>(m_maze.size());
    m_cols = static_cast<int>(m_maze[0].size());

    m_visited.resize(m_rows, std::vector<std::int8_t>(m_cols, 0));
}

// Methods (public)
/**
 * @brief
 * Solve the maze
 * @return true If the maze was solved
 * @return false If the maze couldn't be solved
 *
 */
bool MazeSolver::solve_maze() const
{
    return solve_maze_until(0, 0);
}

/**
 * @brief
 * Convert the maze to a string
 * @return std::string String representation of the maze
 */
std::string MazeSolver::to_string() const noexcept
{
    Maze solutionMaze = m_maze;

    for (const auto &[key, value] : m_solutions)
        solutionMaze[value.first][value.second] = 2;

    std::string maze_string{""};
    maze_string.reserve(m_rows * m_cols);

    for (int i{}; i < m_rows; i++)
    {
        for (int j{}; j < m_cols; j++)
            maze_string += (solutionMaze[i][j] == 2) ? "1 " : "0 ";

        maze_string += "\n";
    }

    return maze_string;
}

// Methods (private)
/**
 * @brief
 * Check if the next position is safe
 * @param row Row of the next position
 * @param col Column of the next position
 * @return true If the next position is safe
 * @return false If the next position is not safe
 */
inline bool MazeSolver::is_safe(const int &row, const int &col) const noexcept
{
    return (row >= 0 && row < m_rows && col >= 0 && col < m_cols &&
            m_maze[row][col] == 1 && !m_visited[row][col]);
}

/**
 * @brief
 * Solve the maze until the end is reached. Uses directional
 * recursion to solve the maze.
 * @param row Row of the current position
 * @param col Column of the current position
 * @return True if the maze was solved
 * @return False if the maze couldn't be solved
 */
bool MazeSolver::solve_maze_until(const int &row,
                                  const int &col) const noexcept
{
    if (row == m_rows - 1 && col == m_cols - 1 &&
        m_maze[row][col] == 1)
    {
        m_solutions.emplace(row * m_cols + col,
                            std::make_pair(row, col));

        return true;
    }

    if (is_safe(row, col))
    {
        m_solutions.emplace(row * m_cols + col,
                            std::make_pair(row, col));

        m_visited[row][col] = 1;

        static const std::array<std::pair<int, int>, 2>
            directions = {{{1, 0}, {0, 1}}};

        for (const auto &[dRow, dCol] : directions)
            if (solve_maze_until(row + dRow, col + dCol))
                return true;

        m_solutions.erase(row * m_cols + col);
        m_visited[row][col] = 0;
    }

    return false;
}
