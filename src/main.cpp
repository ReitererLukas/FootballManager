#include <iostream>

#include "dal/ConfigReader.hpp"
#include "exceptions/Exceptions.hpp"
#include "logic/Game.hpp"
#include "models/Player.hpp"
#include "models/Team.hpp"
#include "cli/CLI.hpp"



int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    std::cout << "config files missing";
    return 1;
  }



  try
  {
    ConfigReader reader;
    reader.readConfig(argv[1]);
    Game game{reader};
    game.startGame();

    
  }
  catch (Exception e)
  {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}