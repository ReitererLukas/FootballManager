#include "SizeDetector.hpp"

// Include headers at the top
#if defined(_WIN64) || defined(_WIN32)
#include <windows.h>
#elif defined(__unix)
#include <sys/ioctl.h>
#include <unistd.h>
#endif

SizeDetector::SizeDetector()
{
#if defined(_WIN64) || defined(_WIN32)
  CONSOLE_SCREEN_BUFFER_INFO csbi;

  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  columns_ = csbi.srWindow.Right - csbi.srWindow.Left + 1;
  rows_ = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
#elif defined(__unix)

  struct winsize w;
  ioctl(fileno(stdout), TIOCGWINSZ, &w);

  rows_ = w.ws_row;
  columns_ = w.ws_col;
#endif
}