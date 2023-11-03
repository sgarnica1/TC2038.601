#include <iostream>
#include "graph/graph.h"

int main()
{
    try
    {
        Graph graph(5);

        graph.add_edge(0, 1);
        graph.add_edge(0, 2);
        graph.add_edge(1, 2);
        graph.add_edge(1, 3);
        graph.add_edge(2, 3);
        graph.add_edge(3, 4);

        std::cout << graph.print_solution() << std::endl;
    }

    catch (const std::exception &e)
    {
        std::cerr << "An error ocurred: " << e.what() << std::endl;
    }
}