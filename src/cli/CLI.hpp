#ifndef CLI_HPP
#define CLI_HPP

#include "../models/Entity.hpp"
#include "../utils/StringUtils.hpp"
#include "Questioner.hpp"
#include "SizeDetector.hpp"
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

class CLI
{
public:
  CLI() = delete;
  CLI(const CLI&) = delete;
  ~CLI() = delete;

  static Questioner simpleQuestion(std::string);
  static void message(std::string);
  static void horizontalLine();
  static void readCLI(std::string&);

  template <typename T>
  static Questioner selectionFromList(std::string question, std::vector<std::shared_ptr<T>> list)
  {
    printList(list, 3, true);

    return simpleQuestion(question);
  }

  template <typename T>
  static void printList(std::vector<std::shared_ptr<T>> list, const int columns = 1, const bool numbers = false)
  {
    SizeDetector size;
    int col_width = (int)size.getColumns() / columns / 2;
    int rows = list.size() / columns;

    for (int row = 0; row < rows; row++)
    {
      for (int col = 0; col < columns; col++)
      {
        int index = col * rows + row + 1;
        if (index >= list.size())
        {
          continue;
        }
        std::string number = std::to_string(index);
        number = StringUtils::addPrefixUntilNLong(number, ' ', 3);

        std::stringstream ss;
        if (numbers)
        {
          ss << number << ". ";
        }
        ss << *list.at(index);
        std::string out = ss.str();
        std::string placeholder(col_width - out.length(), ' ');
        std::cout << out << placeholder;
      }
      std::cout << std::endl;
    }
  }
};

#endif // CLI_HPP