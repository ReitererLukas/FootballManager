#include "GameView.hpp"

std::string GameView::getViewText()
{
  if (view_ == View::HOME)
  {
    return "Home Screen";
  }
  else if (view_ == View::TEAM_HUB)
  {
    return "Team Management";
  }
  else if (view_ == View::TRANSFER_HUB)
  {
    return "Transfer Market";
  }
  else if (view_ == View::YOUTH_ACADEMY)
  {
    return "Youth Academy";
  }
}