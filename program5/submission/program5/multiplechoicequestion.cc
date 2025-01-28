// copyright lily deller
#include "multiplechoicequestion.h"

#include <iostream>
using std::cout;
using std::endl;

namespace csce240_program5 {

// our default constructor
MultipleChoiceQuestion::MultipleChoiceQuestion()
    : question_(""), num_choices_(0), choices_(nullptr), correct_answers_(nullptr) {}

// the constucter w question
MultipleChoiceQuestion::MultipleChoiceQuestion(const string& question)
    : question_(question), num_choices_(0), choices_(nullptr), correct_answers_(nullptr) {}

// constructer w question and choices
MultipleChoiceQuestion::MultipleChoiceQuestion(const string& question, unsigned int num_choices,
                                               const string* choices)
    : question_(question), num_choices_(num_choices) {
  choices_ = new string[num_choices];
  correct_answers_ = new bool[num_choices];
  for (unsigned int i = 0; i < num_choices; ++i) {
    choices_[i] = choices[i];
    correct_answers_[i] = false;  // default for  all answers incorrect
  }
}

// constructor w question choices & correct answers
MultipleChoiceQuestion::MultipleChoiceQuestion(const string& question, unsigned int num_choices,
                                               const string* choices, const bool* correct_answers)
    : question_(question), num_choices_(num_choices) {
  choices_ = new string[num_choices];
  correct_answers_ = new bool[num_choices];
  for (unsigned int i = 0; i < num_choices; ++i) {
    choices_[i] = choices[i];
    correct_answers_[i] = correct_answers[i];
  }
}

// the copy constructor
MultipleChoiceQuestion::MultipleChoiceQuestion(const MultipleChoiceQuestion& other) {
  CopyFrom(other);
}

// assign operator
MultipleChoiceQuestion& MultipleChoiceQuestion::operator=(const MultipleChoiceQuestion& other) {
  if (this != &other) {
    Clear();
    CopyFrom(other);
  }
  return *this;
}

// destructor
MultipleChoiceQuestion::~MultipleChoiceQuestion() {
  Clear();
}

// set answer choices
void MultipleChoiceQuestion::SetAnswerChoices(unsigned int num_choices, const string* choices,
                                              const bool* correct_answers) {
  Clear();
  num_choices_ = num_choices;
  choices_ = new string[num_choices];
  correct_answers_ = new bool[num_choices];
  for (unsigned int i = 0; i < num_choices; ++i) {
    choices_[i] = choices[i];
    correct_answers_[i] = correct_answers[i];
  }
}

// to print the question and answers
void MultipleChoiceQuestion::Print(bool show_correct) const {
  cout << question_ << endl;
  for (unsigned int i = 0; i < num_choices_; ++i) {
    cout << (i + 1) << ". " << choices_[i];
    if (show_correct && correct_answers_[i]) {
      cout << " (correct)";
    }
    cout << endl;
  }
}

// help so we can copy data
void MultipleChoiceQuestion::CopyFrom(const MultipleChoiceQuestion& other) {
  question_ = other.question_;
  num_choices_ = other.num_choices_;
  if (num_choices_ > 0) {
    choices_ = new string[num_choices_];
    correct_answers_ = new bool[num_choices_];
    for (unsigned int i = 0; i < num_choices_; ++i) {
      choices_[i] = other.choices_[i];
      correct_answers_[i] = other.correct_answers_[i];
    }
  } else {
    choices_ = nullptr;
    correct_answers_ = nullptr;
  }
}

// helper to clear dynamic memory
void MultipleChoiceQuestion::Clear() {
  delete[] choices_;
  delete[] correct_answers_;
  choices_ = nullptr;
  correct_answers_ = nullptr;
  num_choices_ = 0;
}

}  // namespace csce240_program5
