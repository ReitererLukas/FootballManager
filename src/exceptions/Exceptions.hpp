#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <string>

class Exception : public std::exception
{
protected:
  std::string message_;

public:
  Exception(const std::string& message) : message_(message) {}

  Exception(const Exception&) = default; // needed to throw exceptions

  Exception& operator=(const Exception& exception) = delete;

  virtual ~Exception() = default;

  const char* what() const noexcept override { return message_.c_str(); }

};

class ConfigFileException : public Exception
{
public:
  explicit ConfigFileException() : Exception("Invalid input config file!") {}
};

class DateParseException : public Exception
{
public:
  explicit DateParseException(const std::string& date) : Exception(date + " not parsable!") {}
};

class FileNotFoundException : public Exception
{
public:
  explicit FileNotFoundException(const std::string& file) : Exception("File" + file + " not found!") {}
};


#endif // EXCEPTIONS_HPP