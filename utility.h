#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <string>
#include <vector>

/*
  Split a line in a list of string according to the delimeter delim
*/
std::vector<std::string> split(const std::string& line, char delim);

#endif