// copyright lily deller
#include "truefalsequestion.h"

namespace csce240_program5 {

// constructor
TrueFalseQuestion::TrueFalseQuestion(string question, bool answer)
    : Question(question), correct_answer(answer) {}

// printfunction
void TrueFalseQuestion::Print(bool show_answer) const {
  cout << "Question: " << GetQuestion() << endl;
  if (show_answer) {
    cout << "Correct Answer: " << (correct_answer ? "true" : "false") << endl;
  }
}

}  // namespace csce240_program5
