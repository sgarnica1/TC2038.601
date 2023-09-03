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
MazeSolver::MazeSolver(const std::vector<std::vector<int>> &maze,
                       const int &rows, const int &cols)
    : m_maze{maze}, m_rows{rows}, m_cols{cols}
{
}

// Methods (public)
/**
 * @brief
 * Solve the maze
 * @return true If the maze was solved
 * @return false If the maze couldn't be solved
 * @time_complexity O(2^(n^2))
 * @space_complexity O(n^2)
 */
bool MazeSolver::solve_maze()
{
    if (solve_maze_until(0, 0))
        return true;

    return false;
}

/**
 * @brief
 * Convert the maze to a string
 * @return std::string String representation of the maze
 * @time_complexity O(n^2)
 * @space_complexity O(n^2)
 */
std::string MazeSolver::to_string() const noexcept
{
    std::string maze_string{""};
    maze_string.reserve(m_rows * m_cols);

    for (int i{}; i < m_rows; i++)
    {
        for (int j{}; j < m_cols; j++)
            maze_string += m_solutions.count(i * m_cols + j) ? "1 " : "0 ";

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
 * @time_complexity O(1)
 * @space_complexity O(1)
 */
bool MazeSolver::is_safe(const int &row, const int &col)
{
    return (row >= 0 && row < m_rows && col >= 0 && col < m_cols &&
            m_maze[row][col] == 1);
}

/**
 * @brief
 * Solve the maze until the end is reached
 * @param row Row of the current position
 * @param col Column of the current position
 * @return True if the maze was solved
 * @return False if the maze couldn't be solved
 * @time_complexity O(2^(n^2)) as the worst case is when the maze is solved by
 *                             traversing the whole maze
 * @space_complexity O(n^2) as the worst case is when the maze is solved by
 *                         traversing the whole maze
 */
bool MazeSolver::solve_maze_until(const int &row,
                                  const int &col)
{
    if (row == m_rows - 1 && col == m_cols - 1 &&
        m_maze[row][col] == 1)
    {
        m_solutions[row * m_cols + col] = {row, col};
        return true;
    }

    if (is_safe(row, col))
    {
        m_solutions[row * m_cols + col] = {row, col};

        if (solve_maze_until(row + 1, col))
            return true;

        if (solve_maze_until(row, col + 1))
            return true;

        m_solutions.erase(m_solutions.size() - 1);
    }

    return false;
}
