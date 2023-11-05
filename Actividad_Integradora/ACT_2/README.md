# Urban Network Optimization Project 🌐

## Course Details 🎓

- **Course:** TC2038.601 - Análisis de Algoritmos Avanzados (Advanced Algorithms Analysis)
- **Date:** Semester August - December 2023
- **Professor:** Ramona Nájera Fuentes

## Team Information 🚀

| Name              | Student ID | Github User                                             |
| ----------------- | ---------- | ------------------------------------------------------- |
| Alejandra Cabrera | A01704463  | [alejandraa-cruiz](https://github.com/alejandraa-cruiz) |
| Carlos Salguero   | A00833341  | [salgue441](https://github.com/salgue441)               |
| Sergio Garnica    | A01704025  | [sgarnica](https://github.com/sgarnica1)                |

## Overview 🌟

This program is designed to process and analyze graph data represented as adjacency matrices for weighted graphs. It is tailored for applications in urban planning and infrastructure development, specifically for optimizing fiber optic cabling between neighborhoods (colonias) and determining efficient routes for physical mail delivery within a city. Additionally, it assesses the maximum data transmission capacity between neighborhoods and aids in identifying the nearest utility central for new service installations.

## Key Features 🔑

1. Optimal Fiber Optic Cabling:

   - Reads an input file containing a graph represented as an adjacency matrix with weights corresponding to distances in kilometers.

   - Determines the optimal way to lay fiber optic cables to ensure connectivity between any two neighborhoods.

2. Shortest Mail Delivery Route:

   - Calculates the shortest possible route that visits each neighborhood exactly once and returns to the starting point, facilitating the physical distribution of account statements, advertisements, and notifications.

3. Maximum Data Flow Analysis:

   - Processes another N x N matrix representing the maximum data transmission capacity between neighborhoods, taking into account electromagnetic interference present in the city.

4. Nearest Utility Central Identification:

   - Given the geographical locations of various "centrals" and a new service installation, the program calculates the nearest central to the new installation.

## Input Format 📥

The program reads input from a text file containing the following information:

- The first line contains the number of neighborhoods (colonias) in the city.
- An NxN matrix representing the graph with distances in kilometers between each neighborhood.
- An NxN matrix representing the maximum data transmission capacity between neighborhoods.
- A list of N ordered pairs in the form (x, y) representing the coordinates of the centrales, along with the location of the new central

## Output Format 📤

The program outputs the following information:

1. **Fiber Cabling plan**: a list of edges in the form (neighborhood 1, neighborhood 2) representing the optimal fiber optic cabling plan.
2. **Shortest Mail Delivery Route**: a list of neighborhoods in the order they should be visited to minimize the distance traveled.
3. **Maximum Data Flow**: a list of edges in the form (neighborhood 1, neighborhood 2) representing the maximum data transmission capacity between neighborhoods.
4. **Nearest Utility Central**: the coordinates of the nearest central to the new service installation.

## How to Run 🏃‍♀️

To use the program, provide the required input files with the specified formats. The program will process the data and output the results in a clear and concise manner, suitable for further analysis or direct implementation in urban infrastructure projects.

```{bash}
./run.sh <input_files>
```

## Additional Notes 📝

- The program assumes that all distances and capacities are provided in consistent units and are accurate.
- The shortest route calculation for mail delivery is based on the Traveling Salesman Problem, which is NP-hard; hence, the solution may approximate the shortest path in larger datasets.
- The maximum data flow is calculated using algorithms suited for network flow problems, such as the Ford-Fulkerson method.
- The nearest central identification is based on the Euclidean distance between points on a plane.
