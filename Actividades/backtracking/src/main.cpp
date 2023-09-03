
// C++ standard library
#include <iostream>

// Project files
#include "./maze_solver/maze_solver.cpp"

int main()
{
    int rows, cols;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;

    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    std::vector<std::vector<int>> maze(rows, std::vector<int>(cols));

    std::cout << "Enter the maze: " << std::endl;
    for (auto &row : maze)
    {
        for (auto &col : row)
        {
            std::cin >> col;
        }
    }

    MazeSolver maze_solver(maze, rows, cols);

    std::cout << "The maze is: " << std::endl;
    maze_solver.solve_maze();

    std::cout << maze_solver.to_string() << std::endl;
}