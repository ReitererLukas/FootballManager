#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../exceptions/Exceptions.hpp"
#include "../utils/Date.hpp"
#include "../utils/StringUtils.hpp"
#include "PlayerPosition.hpp"
#include <ctime>
#include <string>

class Player
{
private:
  long id_;
  std::string shortName_;
  std::string longName_;
  int ranking_;
  int potential_;
  Date dateOfBirth_;

public:
  Player(std::string line);
  Player(const Player&) = delete;
  Player& operator=(const Player&) = delete;
  virtual ~Player() = default;


  int getId() const { return id_; }

  std::string getShortName() const { return shortName_; }


  friend std::ostream& operator<<(std::ostream& out, const Player& game);
};

#endif // PLAYER_HPP