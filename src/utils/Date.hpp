#ifndef DATE_HPP
#define DATE_HPP

#include <string>
#include <vector>
#include "StringUtils.hpp"
#include "../exceptions/Exceptions.hpp"

class Date
{
private:
  int year_;
  int month_;
  int day_;

public:
  Date() : year_{0}, month_{0}, day_{0} {}

  Date(std::string& parsableInput) {
    std::vector<std::string> tokens;
    StringUtils::splitString(parsableInput, "/", tokens);

    if(parsableInput.length() == 0 || tokens.size() != 3) {
        throw new DateParseException(parsableInput);
    }

    day_ = stoi(tokens.at(0)); 
    month_ = stoi(tokens.at(1)); 
    year_ = stoi(tokens.at(2)); 
  }

  Date(const Date&) = delete;

  Date& operator=(const Date&) = default;

  virtual ~Date() = default;
};

#endif // DATE_HPP