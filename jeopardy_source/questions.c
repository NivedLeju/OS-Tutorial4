/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U: Operating Systems
 * <Group Member:>
 * Darren E. Constantine - 100782701
 * Abdul Shahid - 100709858
 * Nived Leju Ramachandran Sonia - 100782317
 */
#include "questions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

question questions[NUM_CATEGORIES][NUM_QUESTIONS / NUM_CATEGORIES];
// Initializes the array of questions for the game
void initialize_game(void) {

  printf("     ____.                                   .___\n");
  printf("    |    | ____  ____ ___________ _______  __| _/__.__.\n");
  printf("    |    |/ __ \\/  _ \\\\____ \\__  \\\\_  __ \\/ __ <   |  |\n");
  printf("/\\__|    \\  ___(  <_> )  |_> > __ \\|  | \\/ /_/ |\\___  |\n");
  printf("\\________|\\___  >____/|   __(____  /__|  \\____ |/ ____|\n");
  printf("              \\/      |__|       \\/           \\/\\/     \n");

  // initialize each question struct and assign it to the questions array
  questions[0][0] = (question){
      .category = categories[0],
      .question =
          "This language is used to design the basic structure of web pages.",
      .answer = "HTML",
      .value = 100,
      .answered = false};
  questions[0][1] =
      (question){.category = categories[0],
                 .question = "Lines of code that are ignored by the compiler.",
                 .answer = "Comments",
                 .value = 200,
                 .answered = false};
  questions[0][2] = (question){
      .category = categories[0],
      .question = "A programming language that is converted into machine "
                  "instructions without a compiler is called this.",
      .answer = "Interpreted",
      .value = 300,
      .answered = false};
  questions[0][3] =
      (question){.category = categories[0],
                 .question = "This language was created by James Gosling and "
                             "Sun Microsystems Inc starting in 1991.",
                 .answer = "Java",
                 .value = 400,
                 .answered = false};

  questions[1][0] =
      (question){.category = categories[1],
                 .question = "This type of search cuts the data set in half "
                             "each time it fails to find the correct answer.",
                 .answer = "Binary",
                 .value = 100,
                 .answered = false};
  questions[1][1] = (question){
      .category = categories[1],
      .question =
          "This type of function calls itself within its own code block.",
      .answer = "Recursive",
      .value = 200,
      .answered = false};
  questions[1][2] =
      (question){.category = categories[1],
                 .question = "A non-comparative sorting algorithm that uses "
                             "buckets and a positional number system.",
                 .answer = "Radix",
                 .value = 300,
                 .answered = false};
  questions[1][3] = (question){
      .category = categories[1],
      .question = "The last name of the creator of the algorithm for finding "
                  "the shortest paths between nodes in a weighted graph.",
      .answer = "Dijkstra",
      .value = 400,
      .answered = false};

  questions[2][0] = (question){.category = categories[2],
                               .question = "This is what DBMS stands for.",
                               .answer = "Database Management System",
                               .value = 100,
                               .answered = false};
  questions[2][1] =
      (question){.category = categories[2],
                 .question = "The most popular type of database used today.",
                 .answer = "Oracle",
                 .value = 200,
                 .answered = false};
  questions[2][2] = (question){
      categories[2],
      .question =
          "A database that runs over the internet is said to reside here.",
      .answer = "Cloud", .value = 300, .answered = false};
  questions[2][3] =
      (question){.category = categories[2],
                 .question = "The first commercial database language to use "
                             "Edgar F Codd's relational model.",
                 .answer = "SQL",
                 .value = 400,
                 .answered = false};
}

// Displays each of the remaining categories and question dollar values that
// have not been answered

// Displays the question for the category and dollar value
void display_question(int category, int value) {
  // // find the question number
  // int num;
  // for (int i = 0; i < 4; i ++) {
  //   if (strcmp(questions[i].category, category) == 0) {
  //     num = i + (value / 100) - 1;
  //   }
  // }
  // // print the question
  // printf("Question for category %s, value %d:\n");
  // category--;
  int variable = (value / 100) - 1;
  printf("Question: %s", *questions[category][variable].question);
}

// Returns true if the answer is correct for the question for that category and
// dollar value
bool valid_answer(int category, int value, char *answer) {
  int val = (value / 100) - 1;
  questions[category][val].answered = true;
  // Look into string comparison functions
  if (strcasecmp(answer, *questions[category][val].answer) == 0) {
    printf("\nThis is correct! $%d have been added to your score!", value);
    return true;
  }
  else {
    printf("\nNot quite! The correct answer is: %s\nBetter luck next time!\n", *questions[category][val].answer);
    return false;
  }
  return false;
}

// Returns true if the question has already been answered
bool already_answered(int category, int value) {
  // lookup the question and see if it's already been marked as answered
  return questions[category][(value / 100) - 1].answered;
}

void display_grid() {
  printf("\n");
  // print categories and dollar values for each unanswered question in
  //  questions array print category headings
  printf(" -------------------------------------------\n");
  printf("| Programming |  Algorithms  |  Databases   |\n");
  printf(" -------------------------------------------\n");
  for (int i = 0; i < (NUM_QUESTIONS / NUM_CATEGORIES); i++) {
    for (int j = 0; j < NUM_CATEGORIES; j++)
      printf(" _____________ ");
    printf("\n");
    for (int j = 0; j < NUM_CATEGORIES; j++)
      printf("|             |");
    printf("\n");

    for (int j = 0; j < NUM_CATEGORIES; j++)
      printf("|             |");
    printf("\n");
    for (int j = 0; j < NUM_CATEGORIES; j++)
      if (questions[j][i].answered)
        printf("|     XXX     |", (i + 1) * 100);
      else
        printf("|     %d     |", (i + 1) * 100);
    printf("\n");
    for (int j = 0; j < NUM_CATEGORIES; j++)
      printf("|             |");
    printf("\n");

    for (int j = 0; j < NUM_CATEGORIES; j++)
      printf("|_____________|");
    printf("\n");
  }
}