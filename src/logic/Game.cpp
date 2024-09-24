#include "Game.hpp"

#include "../cli/CLI.hpp"
#include "../cli/Questioner.hpp"


Game::Game(ConfigReader& reader)
{
  leagues_ = reader.getLeagues();
  teams_ = reader.getTeams();

  reader.clearReader();
}

void Game::startGame()
{
  current_view_ = GameView::HOME;

  Questioner name_question = CLI::simpleQuestion("Manager name?");
  manager_name_ = name_question.getAnswer();
  CLI::message("Hello coach " + manager_name_);
  CLI::horizontalLine();

  Questioner team_question = CLI::selectionFromList("Select your Team", teams_);
  team_ = teams_.at(stoi(team_question.getAnswer()));
  CLI::message(team_->getName() + " is happy to have you signed coach!");
  CLI::horizontalLine();
}

void Game::gameLoop()
{
  while(true)
  {
    std::string input;
    CLI::readCLI(input);
    command_manager_.executeCommand(input, *this);
  }
}


std::ostream& operator<<(std::ostream& out, Game& game)
{
  out << "Game" << std::endl;
  return out;
}