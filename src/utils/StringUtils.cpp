#include "StringUtils.hpp"

void StringUtils::splitString(std::string s, std::string delimiter, std::vector<std::string>& tokens)
{
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();

  while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos)
  {
    std::string token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    if (token != "")
    {
      tokens.push_back(token);
    }
  }

  std::string last = s.substr(pos_start);
  if (last != "")
  {
    tokens.push_back(last);
  }
}

void StringUtils::splitStringWithArrays(std::string s, std::string delimiter, std::string arrayDelimiter,
                                        std::vector<std::string>& tokens)
{
  std::vector<std::string> arrays;
  splitString(s, arrayDelimiter, arrays);

  int counter = 0;
  // std::cout << arrays.size() << std::endl;
  for (auto array : arrays)
  {
    // std::cout << array << std::endl;
    if (counter % 2 == 1)
    {
      tokens.push_back(array);
    }
    else
    {
      splitString(array, delimiter, tokens);
    }
    counter++;
  }
}

bool StringUtils::endsWith(const std::string& fullString, const std::string& ending)
{
  if (fullString.length() < ending.length())
  {
    return false;
  }
  return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
}


std::string StringUtils::addPrefixUntilNLong(std::string& text, const char prefix, int length)
{
  while(text.length() < length)
  {
    text = prefix + text;
  }

  return text;
}