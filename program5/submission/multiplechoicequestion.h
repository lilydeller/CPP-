// copyright lily deller
#ifndef MULTIPLECHOICEQUESTION_H
#define MULTIPLECHOICEQUESTION_H

#include <string> 
using std::string;

namespace csce240_program5 {

class MultipleChoiceQuestion {
 private:
  string question_;
  unsigned int num_choices_;
  string* choices_;
  bool* correct_answers_;

 public:
  // constructers
  MultipleChoiceQuestion();
  explicit MultipleChoiceQuestion(const string& question);
  MultipleChoiceQuestion(const string& question, unsigned int num_choices,
                         const string* choices);
  MultipleChoiceQuestion(const string& question, unsigned int num_choices,
                         const string* choices, const bool* correct_answers);

  // copy constructer
  MultipleChoiceQuestion(const MultipleChoiceQuestion& other);

  // assign operator
  MultipleChoiceQuestion& operator=(const MultipleChoiceQuestion& other);

  // destructor
  ~MultipleChoiceQuestion();

  // member functions
  void SetAnswerChoices(unsigned int num_choices, const string* choices,
                        const bool* correct_answers);
  void Print(bool show_correct) const;

 private:
  void CopyFrom(const MultipleChoiceQuestion& other);
  void Clear();
};

}  // namespace csce240_program5

#endif
