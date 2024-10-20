#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

#include "circles.hpp"

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    std::cerr << "Too few arguments" << '\n';
    return 1;
  }
  int tries = 0;
  int seed = 0;
  try
  {
    tries = std::stoi(argv[1]);
    if (argc > 2)
    {
      seed = std::stoi(argv[2]);
    }
    if ((tries <= 0) || (seed < 0))
    {
      throw std::invalid_argument("");
    }
  }
  catch (const std::invalid_argument&)
  {
    std::cerr << "Invalid arguments" << '\n';
    return 1;
  }

  babinov::CircleData data;
  while (!std::cin.eof())
  {
    std::cin >> data;
    if (std::cin.fail())
    {
      std::cerr << "Invalid values" << '\n';
      return 1;
    }
    auto start = std::chrono::steady_clock::now();
    double square = babinov::getSquare(data, seed, tries);
    auto end = std::chrono::steady_clock::now();
    std::cout << square << ' ' << std::chrono::duration_cast< std::chrono::milliseconds >(end - start).count() << '\n';
  }
  return 0;
}
