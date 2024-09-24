#include "CommandManager.hpp"

#include "hubs/TeamHubCommand.hpp"

CommandManager::CommandManager() { commands_.push_back(new TeamHubCommand()); }

CommandManager::~CommandManager()
{
  for (auto command : commands_)
  {
    delete command;
  }
}

void CommandManager::executeCommand(std::string& input, Game& game)
{
  std::string name;
  for (BaseCommand* command : commands_)
  {
    if (command->getName() == name && game.getCurrentView() == command->getUsableView())
    {
      command->execute(game);
    }
  }
}