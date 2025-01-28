// copyright lily deller
#ifndef SHORTANSWERQUESTION_H
#define SHORTANSWERQUESTION_H

#include <string>
#include <iostream>
#include "question.h"

using std::string;
using std::cout;
using std::endl;

namespace csce240_program5 {

class ShortAnswerQuestion : public Question {
 private:
  string correct_answer;

 public:
  // constructor w default arguments
  explicit ShortAnswerQuestion(string question = "?", string answer = "");

  // accesser and mutator for correct_answer
  string GetCorrectAnswer() const { return correct_answer; }
  void SetCorrectAnswer(const string &answer) { correct_answer = answer; }

  // print 
  void Print(bool show_answer) const;
};

}  // namespace csce240_program5

#endif  // SHORTANSWERQUESTION_H
