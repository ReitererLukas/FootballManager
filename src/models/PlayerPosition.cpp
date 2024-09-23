#include <string>
#include <vector>

#include "PlayerPosition.hpp"
#include "../utils/StringUtils.hpp"

PlayerPosition PlayerPosition::getPosition(std::string positions)
{
  std::vector<std::string> tokens;
  StringUtils::splitString(positions, ", ", tokens);
  if (tokens.size() == 0)
  {
    return PlayerPosition::NONE;
  }

  std::string pos = tokens.at(0);
  if (pos == "ST" || pos == "LW" || pos == "RW" || pos == "CF")
  {
    return PlayerPosition::FORWARD;
  }
  else if (pos == "CM" || pos == "CDM" || pos == "CAM" || pos == "RM" || pos == "LM")
  {
    return PlayerPosition::MIDFIELDER;
  }
  else if (pos == "CB" || pos == "RB" || pos == "LB" || pos == "RWB" || pos == "LWB")
  {
    return PlayerPosition::DEFENDER;
  }
  else if (pos == "GK")
  {
    return PlayerPosition::GOALKEEPER;
  }
  else
  {
    return PlayerPosition::NONE;
  }
}