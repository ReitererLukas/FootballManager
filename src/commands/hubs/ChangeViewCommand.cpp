#include "ChangeViewCommand.hpp"
#include "../../cli/CLI.hpp"

void ChangeViewCommand::execute(Game& game)
{
  game.setView(go_to_view_);
  CLI::message("Now entering the " + go_to_view_.getViewText());
}