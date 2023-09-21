cd src

# Compile and run the maze program
g++ -std=c++20 main.cpp maze_solver/maze_solver.cpp -o maze_program
./maze_program


# Remove the maze program
rm maze_program

# Move back to the root directory
cd ..