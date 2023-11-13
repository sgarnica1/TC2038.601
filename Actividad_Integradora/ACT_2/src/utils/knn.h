/**
 * @file knn.h
 * @author Alejandra Cabrera
 * @author Carlos Salguero
 * @author Sergio Garnica
 * @brief KNN algorithm to find closest central
 * @version 0.1
 * @date 2023-11-05
 *
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <limits> // for std::numeric_limits

#ifndef KNN_H
#define KNN_H

/**
 * @brief KNN algorithm to find closest central to a house. Calculates the shortest distance from
 * a house to a central using Euclidean distance.
 *
 * @details This method finds the closest central to a house using the KNN algorithm
 * using Euclidean distance.
 *
 * @details The formula for Euclidean distance in two dimensions is D = (x2 − x1)^2 + (y2 − y1)^2,
 * where D is the Euclidean distance, and (x1, y1) and (x2, y2) are the Cartesian coordinates of the
 * two points.
 *
 * @param[in] centrals Vector of pairs of coordinates of centrals
 * @param[in] house Pair of coordinates of the house
 *
 * @return void
 *
 * @timecomplexity O(n)
 * @spacecomplexity O(1)
 */

void knn(std::vector<std::pair<int, int>> &centrals, std::pair<int, int> &house)
{
  // Find the closest central using Euclidean distance
  int closestCentralIndex = -1;
  double minDistance = std::numeric_limits<double>::max(); // Initialize with a large value

  for (int i = 0; i < centrals.size(); ++i)
  {
    double distance = std::sqrt(std::pow(house.first - centrals[i].first, 2) +
                                std::pow(house.second - centrals[i].second, 2));

    if (distance < minDistance)
    {
      minDistance = distance;
      closestCentralIndex = i;
    }
  }

  if (closestCentralIndex != -1)
  {
    std::cout << "\nFind closest central to new location using KNN Algorithm & Euclidean distance:\n";
    std::cout << "Location: (" << house.first << ", " << house.second << ")\n";
    std::cout << "Central is at: (" << centrals[closestCentralIndex].first << ", " << centrals[closestCentralIndex].second << ")\n";
    std::cout << "Distance to new location: " << minDistance << std::endl;
  }
  else
  {
    std::cout << "No central found." << std::endl;
  }
}

#endif // KNN_H