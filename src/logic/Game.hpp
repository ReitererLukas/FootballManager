#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <vector>
#include <string>

#include "../models/Team.hpp"
#include "../models/League.hpp"
#include "../dal/ConfigReader.hpp"

class Game
{
private:
  std::vector<std::shared_ptr<League>> leagues_;
  std::vector<std::shared_ptr<Team>> teams_;
  std::string manager_name_;
  std::shared_ptr<Team> team_;

public:
  Game(ConfigReader&);
  Game(Game&) = delete;
  ~Game() = default;

  void startGame();

  friend std::ostream& operator<<(std::ostream& out, Game& game);
};

#endif // GAME_HPP