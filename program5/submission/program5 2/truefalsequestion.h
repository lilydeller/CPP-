// copyright lily deller
#ifndef TRUEFALSEQUESTION_H
#define TRUEFALSEQUESTION_H

#include <string>
#include <iostream>
#include "question.h"

using std::string;
using std::cout;
using std::endl;

namespace csce240_program5 {

class TrueFalseQuestion : public Question {
 private:
  bool correct_answer; // will hold whether the answer is true or false

 public:
  // constructer w default arguments
  explicit TrueFalseQuestion(string question = "?", bool answer = true);

  // accessor and mutator for correct_answer
  bool GetCorrectAnswer() const { return correct_answer; }
  void SetCorrectAnswer(bool answer) { correct_answer = answer; }

  // print  function
  void Print(bool show_answer) const;
};

}  // namespace csce240_program5

#endif // TRUEFALSEQUESTION_H
