#include "utility.h"
#include <sstream>
/*
  Split a line in a list of string according to the delimeter delim
*/
std::vector<std::string> split(const std::string& line, char delim)
{
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream tokenStream(line);
  while (std::getline(tokenStream, token, delim))
    {
      tokens.push_back(token);
    }
  return tokens;
}
