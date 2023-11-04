#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <filesystem>

#include "graph.h"

int main(int argc, char **argv)
{
  Graph graph(5);
  graph.addEdge(0, 1, 10);
  graph.addEdge(0, 2, 10);
  graph.addEdge(1, 2, 2);
  graph.addEdge(1, 3, 4);
  graph.addEdge(1, 4, 8);

  std::cout << "Hello world!" << std::endl;
  return 0;
}