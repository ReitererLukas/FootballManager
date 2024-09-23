#ifndef CONFIGREADER_HPP
#define CONFIGREADER_HPP

#include "../models/League.hpp"
#include "../models/Player.hpp"
#include "../models/Team.hpp"
#include <filesystem>
#include <fstream>
#include <memory>
#include <string>
#include <vector>

class ConfigReader
{
private:
  std::vector<std::shared_ptr<League>> leagues_;
  std::vector<std::shared_ptr<Team>> teams_;

  char getPathSeparator();

public:
  ConfigReader() = default;
  ConfigReader(ConfigReader&) = delete;
  ~ConfigReader() = default;

  void readConfig(const std::string& config_path);
  void readPlayersOfTeam(std::string& file_path, std::shared_ptr<Team> team);

  void clearReader()
  {
    leagues_.clear();
    teams_.clear();
  }

  std::vector<std::shared_ptr<League>> getLeagues() { return leagues_; }
  std::vector<std::shared_ptr<Team>> getTeams() { return teams_; }
};

#endif // CONFIGREADER_HPP