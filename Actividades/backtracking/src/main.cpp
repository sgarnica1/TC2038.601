/**
 * @file main.h
 * @author Carlos Salguero
 * @author Sergio Garnica
 * @author Alejandra Cabrera
 * @brief Entry point of the program
 * @version 0.1
 * @date 2023-09-02
 *
 * @copyright Copyright (c) 2023
 *
 */
// C++ standard library
#include <iostream>

// Project files
#include "./maze_solver/maze_solver.h"

int main()
{
    int rows, cols;

    std::cout << "Enter the number of rows: ";
    if (!(std::cin >> rows))
    {
        std::cerr << "Invalid input\n";
        return 1;
    }

    std::cout << "Enter the number of columns: ";
    if (!(std::cin >> cols))
    {
        std::cerr << "Invalid input\n";
        return 1;
    }

    Maze maze(rows, std::vector<int>(cols));

    std::cout << "Enter the maze:\n";
    for (auto &row : maze)
    {
        for (auto &col : row)
        {
            if (!(std::cin >> col) || (col != 0 && col != 1))
            {
                std::cerr << "Invalid input\n";
                return 1;
            }
        }
    }

    MazeSolver maze_solver(maze);
    std::cout << "\nThe maze solution is: \n";
    maze_solver.solve_maze();
    std::cout << maze_solver.to_string() << '\n';
}
