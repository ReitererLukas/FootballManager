#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <vector>
#include <string>

#include "../models/Team.hpp"
#include "../models/League.hpp"
#include "../dal/ConfigReader.hpp"
#include "../commands/CommandManager.hpp"
#include "GameView.hpp"

class Game
{
private:
  std::vector<std::shared_ptr<League>> leagues_;
  std::vector<std::shared_ptr<Team>> teams_;
  std::string manager_name_;
  std::shared_ptr<Team> team_;
  GameView current_view_;
  CommandManager command_manager_;

public:
  Game(ConfigReader&);
  Game(Game&) = delete;
  ~Game() = default;

  void startGame();
  void gameLoop();

  void setView(GameView view) { current_view_ = view; }
  GameView& getCurrentView() { return current_view_; }

  friend std::ostream& operator<<(std::ostream& out, Game& game);
};

#endif // GAME_HPP