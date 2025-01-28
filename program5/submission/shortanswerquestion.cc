// copyright lily deller
#include "shortanswerquestion.h"

namespace csce240_program5 {

// constructer 
ShortAnswerQuestion::ShortAnswerQuestion(string question, string answer)
    : Question(question), correct_answer(answer) {}

// print  function
void ShortAnswerQuestion::Print(bool show_answer) const {
  cout << "Question: " << GetQuestion() << endl;
  if (show_answer) {
    cout << "Correct Answer: " << correct_answer << endl;
  }
}

}  // namespace csce240_program5
