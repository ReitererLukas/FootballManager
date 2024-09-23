#include "Player.hpp"

Player::Player(std::string line)
{
  std::vector<std::string> tokens;
  StringUtils::splitStringWithArrays(line, ",", "\"", tokens);

  if (tokens.size() == 0)
  {
    throw new ConfigFileException();
  }

  id_ = stoi(tokens.at(0));
  shortName_ = tokens.at(1);
  longName_ = tokens.at(2);
  ranking_ = stoi(tokens.at(3));
  potential_ = stoi(tokens.at(4));
  dateOfBirth_ = Date(tokens.at(5));
}

std::ostream& operator<<(std::ostream& out, const Player& player)
{
  out << player.getId() << ": " << player.getShortName();
  return out;
}