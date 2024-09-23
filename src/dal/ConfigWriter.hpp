#ifndef CONFIGWRITER_HPP
#define CONFIGWRITER_HPP

#include "../models/Player.hpp"
#include "../models/Team.hpp"
#include <fstream>
#include <memory>
#include <string>
#include <vector>

class ConfigWriter
{
public:
  ConfigWriter() = delete;
  ConfigWriter(ConfigWriter&) = delete;
  ~ConfigWriter() = delete;

  template <typename T> std::vector<std::shared_ptr<T>> readConfig(const std::string& file_path)
  {
    std::vector<std::shared_ptr<T>> res_list;
    std::ifstream file{file_path};

    if (!file.is_open())
    {
      throw new FileNotFoundException(file_path);
    }

    std::string line;
    while (getline(file, line))
    {
      res_list.push_back(std::make_shared<T>(line));
    }

    file.close();

    return res_list;
  }
};

#endif // CONFIGWRITER_HPP