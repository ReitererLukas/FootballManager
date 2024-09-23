#include "Team.hpp"

#include "../utils/StringUtils.hpp"

Team::Team(std::string team_identifier)
{
  std::vector<std::string> tokens;
  StringUtils::splitString(team_identifier, "_", tokens);

  id_ = stoi(tokens.at(0));
  name_ = tokens.at(1);
}

void Team::addPlayer(std::shared_ptr<Player> player)
{
  players_.push_back(player);
}

std::ostream& operator<<(std::ostream& out, const Team& team)
{
  out << team.getName();
  return out;
}