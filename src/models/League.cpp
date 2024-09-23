#include "League.hpp"

#include "../utils/StringUtils.hpp"
#include <vector>
#include <string>
#include <memory>

League::League(std::string league_identifier)
{
  std::vector<std::string> tokens;
  StringUtils::splitString(league_identifier, "_", tokens);

  id_ = stoi(tokens.at(0));
  name_ = tokens.at(1);
}

void League::addTeam(std::shared_ptr<Team> team)
{
  teams_.push_back(team);
}