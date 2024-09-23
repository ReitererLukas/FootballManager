#ifndef TEAM_HPP
#define TEAM_HPP

#include "../exceptions/Exceptions.hpp"
#include "../utils/Date.hpp"
#include "../utils/StringUtils.hpp"
#include "Player.hpp"
#include "Entity.hpp"
#include <string>
#include <memory>

class Team : public Entity
{
private:
  std::string name_;
  std::vector<std::shared_ptr<Player>> players_;

public:
  Team(std::string line);
  Team(const Team&) = delete;
  Team& operator=(const Team&) = delete;
  virtual ~Team() = default;

  void addPlayer(std::shared_ptr<Player>);

  std::string getName() const { return name_; }

  friend std::ostream& operator<<(std::ostream& out, const Team& game);
};

#endif // TEAM_HPP