#ifndef VIEW_HPP
#define VIEW_HPP

#include <string>

class GameView
{
public:
  enum View {
    HOME=0,
    TEAM_HUB=1,
    TRANSFER_HUB=2,
    YOUTH_ACADEMY=3
  };

  GameView() {}

  GameView(View view) : view_{view} {}

  std::string getViewText();

  bool operator==(GameView& pos)
  {
    return pos.view_ == view_;
  }

  bool operator!=(GameView& pos)
  {
    return !(pos == *this);
  }

private:
  View view_;
};

#endif // VIEW_HPP