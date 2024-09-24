#ifndef BASECOMMAND_HPP
#define BASECOMMAND_HPP

#include <string>
#include "../logic/Game.hpp"
#include "../logic/GameView.hpp"

class BaseCommand
{
private:
  GameView usable_in_view_;

public:
  BaseCommand(GameView usable_in_view) : usable_in_view_{usable_in_view_} {};
  BaseCommand(const BaseCommand&) = delete;
  virtual ~BaseCommand() = default;

  virtual std::string getName() = 0;
  virtual void execute(Game&) = 0;

  GameView& getUsableView() { return usable_in_view_; }
};

#endif // BASECOMMAND_HPP