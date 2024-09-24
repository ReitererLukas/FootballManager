#ifndef CHANGEVIEWCOMMAND_HPP
#define CHANGEVIEWCOMMAND_HPP

#include "../BaseCommand.hpp"
#include "../../logic/GameView.hpp"
#include "../../logic/Game.hpp"

class ChangeViewCommand : public BaseCommand
{
private:
  GameView go_to_view_;

public:
  ChangeViewCommand(GameView go_to_view_) : BaseCommand(GameView::HOME), go_to_view_{go_to_view_} {};
  ChangeViewCommand(const ChangeViewCommand&) = default;
  virtual ~ChangeViewCommand() = default;

  virtual std::string getName() = 0;
  virtual void execute(Game&) override;
};

#endif // CHANGEVIEWCOMMAND_HPP