#ifndef PLAYERPOSITION_HPP
#define PLAYERPOSITION_HPP

#include <string>

class PlayerPosition
{

public:
  enum Positions
  {
    GOALKEEPER,
    DEFENDER,
    MIDFIELDER,
    FORWARD,
    NONE,
  };

  PlayerPosition() {}

  PlayerPosition(Positions position) : position_{position} {}

  static PlayerPosition getPosition(std::string position);

  bool operator==(PlayerPosition& pos)
  {
    return pos.position_ == position_;
  }

  bool operator!=(PlayerPosition& pos)
  {
    return !(pos == *this);
  }

private:
  Positions position_;
};

#endif // PLAYERPOSITION_HPP