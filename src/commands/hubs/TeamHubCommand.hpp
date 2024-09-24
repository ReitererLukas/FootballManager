#ifndef TEAMHUBCOMMAND_HPP
#define TEAMHUBCOMMAND_HPP

#include "ChangeViewCommand.hpp"
#include <string>

class TeamHubCommand : public ChangeViewCommand
{
public:
  TeamHubCommand() : ChangeViewCommand(GameView::TRANSFER_HUB) {};
  TeamHubCommand(const TeamHubCommand&) = default;
  ~TeamHubCommand() = default;


  virtual std::string getName() { return "teamhub"; }
};

#endif // TEAMHUBCOMMAND_HPP