/**
 * @file maze_solver.h
 * @author Carlos Salguero
 * @author Sergio Garnica
 * @author Alejandra Cabrera
 * @brief Test file for the MazeSolver class
 * @version 0.1
 * @date 2023-09-02
 *
 * @copyright Copyright (c) 2023
 *
 */
// C++ Standard Library
#include <iostream>
#include <cassert>

// Project headers
#include "../src/maze_solver/maze_solver.h"

// Functions
/**
 * @brief
 * Test function for the MazeSolver class
 * @param maze Maze to be solved
 */
void testMazeSolver(const Maze &maze)
{
    MazeSolver maze_solver(maze);
    assert(maze_solver.solve_maze() == true);

    std::cout << "The maze solution is: \n";
    std::cout << maze_solver.to_string() << std::endl;
}

/**
 * @brief
 * Main function
 * @return int
 */
int main()
{
    Maze maze1 = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1}};

    testMazeSolver(maze1);

    Maze maze2 = {
        {1, 1, 1, 1, 0, 1},
        {1, 1, 0, 1, 1, 1},
        {1, 0, 0, 1, 0, 1},
        {1, 1, 0, 1, 0, 1},
        {0, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 0, 1}};
    testMazeSolver(maze2);

    Maze maze3 = {
        {1, 0, 0, 1},
        {1, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 0, 1}};
    testMazeSolver(maze3);

    Maze maze4 = {
        {1, 1, 0, 1, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 0, 0, 0, 1, 1},
        {1, 1, 0, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 1, 1, 0, 1, 1},
        {1, 1, 0, 1, 1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 0, 1, 1, 0, 1}};
    testMazeSolver(maze4);
}