#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
#include <vector>

std::vector<std::string> split(const std::string& str, char delimiter) {
  std::vector<std::string> substrings;
  std::size_t start = 0;
  std::size_t end = 0;

  while ((end = str.find(delimiter, start)) != std::string::npos) {
    substrings.push_back(str.substr(start, end - start));
    start = end + 1;
  }

  substrings.push_back(str.substr(start));

  return substrings;
}

#endif