#ifndef STRINGUTILS_HPP
#define STRINGUTILS_HPP

#include <vector>
#include <string>
#include <iostream>

class StringUtils
{
public:
  StringUtils() = delete;
  StringUtils(StringUtils& utils) = delete;
  ~StringUtils() = delete;

  static void splitString(std::string s, std::string delimiter, std::vector<std::string>& tokens);
  static void splitStringWithArrays(std::string s, std::string delimiter, std::string arrayDelimiter,
                                    std::vector<std::string>& tokens);
  static bool endsWith(const std::string& fullString, const std::string& ending);
  static std::string addPrefixUntilNLong(std::string& text, const char prefix, int length);
};

#endif // STRINGUTILS_HPP