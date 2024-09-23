#ifndef SIZEDETECTOR_HPP
#define SIZEDETECTOR_HPP

#include <string>
#include <memory>


class SizeDetector
{
private:
  int columns_;
  int rows_;

public:
  SizeDetector();

  int getColumns() { return columns_;}
  int getRows() { return columns_;}
};

#endif // SIZEDETECTOR_HPP