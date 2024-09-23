#ifndef LEAGUE_HPP
#define LEAGUE_HPP

#include <string>
#include <memory>
#include "Team.hpp"

class League
{
private:
  long id_;
  std::string name_;

  std::vector<std::shared_ptr<Team>> teams_;

public:
  League() = default;
  League(std::string);
  League(const League&) = delete;
  League& operator=(const League&) = delete;
  virtual ~League() = default;

  void addTeam(std::shared_ptr<Team>);


  int getId() const { return id_; }

  std::string getName() const { return name_; }

  friend std::ostream& operator<<(std::ostream&, const League&);
};

#endif // LEAGUE_HPP