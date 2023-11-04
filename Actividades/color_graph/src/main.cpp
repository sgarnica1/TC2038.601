#include <iostream>
#include "graph/graph.h"

int main()
{
  try
  {
    std::cout << "Test Case 1:"
              << "\n\n";
    Graph graph(5);

    graph.add_edge(0, 1);
    graph.add_edge(0, 2);
    graph.add_edge(1, 2);
    graph.add_edge(1, 3);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);

    std::cout << graph.print_solution() << std::endl;

    std::cout << "Test Case 2:"
              << "\n\n";
    Graph graph2(4);

    graph2.add_edge(0, 1);
    graph2.add_edge(0, 2);
    graph2.add_edge(1, 2);
    graph2.add_edge(1, 3);
    graph2.add_edge(2, 3);

    std::cout << graph2.print_solution() << std::endl;

    std::cout << "Test Case 3:"
              << "\n\n";
    Graph graph3(3);

    graph3.add_edge(0, 1);
    graph3.add_edge(0, 2);
    graph3.add_edge(1, 2);

    std::cout << graph3.print_solution() << std::endl;

    std::cout << "Test Case 4:"
              << "\n\n";
    Graph graph4(3);

    graph4.add_edge(0, 1);
    graph4.add_edge(1, 2);

    std::cout << graph4.print_solution() << std::endl;
  }

  catch (const std::exception &e)
  {
    std::cerr << "An error ocurred: " << e.what() << std::endl;
  }
}