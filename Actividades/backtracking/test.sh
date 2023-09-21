
# Test script for the program
# This script will run the program and compare the output to the expected output
# If the output is different, it will print the difference and exit with an error code
cd tests

g++ -std=c++20 test.cpp ../src/maze_solver/maze_solver.cpp -o test
./test

# Clean up
rm test

# Move back to root directory
cd ..