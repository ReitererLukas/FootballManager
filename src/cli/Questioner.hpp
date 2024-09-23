#ifndef QUESTIONER_HPP
#define QUESTIONER_HPP

#include <string>

class Questioner
{
private:
  std::string question_;
  std::string answer_;

public:
  Questioner(std::string& question, std::string& answer) : question_{question}, answer_{answer} {}
  Questioner() = default;
  Questioner(const Questioner&) = default;
  virtual ~Questioner() = default;

  std::string getQuestion() { return question_; }
  std::string getAnswer() { return answer_; }
};

#endif // QUESTIONER_HPP