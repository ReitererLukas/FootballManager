#ifndef COMMANDMANAGER_HPP
#define COMMANDMANAGER_HPP

#include <string>
#include <vector>

class BaseCommand;
class Game;

class CommandManager
{
private:
  std::vector<BaseCommand*> commands_;

public:
  CommandManager();
  CommandManager(const CommandManager&) = delete;
  ~CommandManager();
  CommandManager& operator=(const CommandManager&) = delete;

  void executeCommand(std::string& input, Game& game);
};

#endif // COMMANDMANAGER_HPP