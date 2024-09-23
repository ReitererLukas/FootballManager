#include "CLI.hpp"

#include <iostream>

void CLI::readCLI(std::string& input)
{
  std::getline(std::cin, input);
}

void CLI::message(std::string message)
{
  std::cout << message;
  if(message.back() != '\n') {
    std::cout << std::endl;
  }
}

Questioner CLI::simpleQuestion(std::string question)
{
  std::cout << question;
  if (question.back() != '\n')
  {
    std::cout << std::endl;
  }
  std::cout << "> ";
  std::string input;
  readCLI(input);

  Questioner questioner{question, input};
  return questioner;
}

void CLI::horizontalLine()
{
  std::cout << "=====================" << std::endl << std::endl;
}


