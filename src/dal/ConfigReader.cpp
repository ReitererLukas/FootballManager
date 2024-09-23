#include "ConfigReader.hpp"

void ConfigReader::readConfig(const std::string& config_path)
{
  char separator = getPathSeparator();

  std::shared_ptr<League> current_league;
  for (const auto& entry : std::filesystem::recursive_directory_iterator(config_path + separator + "leagues"))
  {
    std::string path = entry.path().generic_string();
    if (StringUtils::endsWith(path, ".csv"))
    {
      std::size_t last_index = path.find_last_of(separator);
      std::string team_name = path.substr(last_index + 1, path.length() - last_index - 5);
      std::shared_ptr<Team> team = std::make_shared<Team>(team_name);
      current_league->addTeam(team);
      teams_.push_back(team);
      readPlayersOfTeam(path, team);
    }
    else
    {
      std::size_t last_index = path.find_last_of(separator);
      std::string league_name = path.substr(last_index + 1);
      current_league = std::make_shared<League>(league_name);
      leagues_.push_back(current_league);
    }
  }
}

void ConfigReader::readPlayersOfTeam(std::string& file_path, std::shared_ptr<Team> team)
{
  std::ifstream file{file_path};

  if (!file.is_open())
  {
    throw new FileNotFoundException(file_path);
  }

  std::string line;
  while (getline(file, line))
  {
    team->addPlayer(std::make_shared<Player>(line));
  }

  file.close();
}

char ConfigReader::getPathSeparator()
{
#if defined(_WIN64) || defined(_WIN32)
  return '\\';
#elif defined(__unix)
  return '/';
#endif
}