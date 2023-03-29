#include <iostream>
#include <limits>
#include <fstream>
#include "has_repeating_elements.h"
#include "create_new_string.h"

int main()
{
  size_t capacity = 20;
  char* cstring = new char[capacity];
  size_t size = 0;
  std::cin >> std::noskipws;
  size_t const maxSize = std::numeric_limits< size_t >::max();
  if (size == capacity)
  {
    if (capacity == maxSize)
    {
      std::cout << "Too long string" << "\n";
      return 1;
    }
  }
  std::ifstream input_file("input.txt");
  std::ofstream output_file("output.txt");
  if (input_file.is_open())
  {
    input_file >> size;
    char* line = new char[size];
    input_file.ignore();
    input_file.getline(line, size);
    size_t count = 0;
    while (line[count] != '\0') {
      count++;
    }
    bool result = has_repeating_elements(line);
    output_file << result << "\n"; 
    char results[4];
    three_most_repetitive(results, line);
    for (size_t i = 0; i < 4; i++)
    {
      output_file << results[i];
    }
    delete[] line;
    input_file.close();
  }
  else
  {
    std::cout << "File is not open!";
  }
  
}