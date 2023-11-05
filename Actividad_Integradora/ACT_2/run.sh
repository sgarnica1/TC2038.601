#!/bin/bash

# Check if an input file was provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <input_file>"
    exit 1
fi

# Compile the program
g++ -std=c++20 src/main.cpp src/utils/logger/logger.cpp src/graph/graph.cpp -o bin/main

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    # Run the program with the input file
    ./bin/main "$1"
else
    echo "Compilation failed."
    exit 1
fi
