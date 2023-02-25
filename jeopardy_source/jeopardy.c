/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U: Operating Systems
 * <Group Member:>
 * Darren E. Constantine - 100782701
 * Abdul Shahid - 100709858
 * Nived Leju Ramachandran Sonia - 100782317
 */

#include "jeopardy.h"
#include "players.h"
#include "questions.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here
extern question questions[NUM_CATEGORIES][NUM_QUESTIONS / NUM_CATEGORIES];
// Processes the answer from the user containing what is or who is and tokenizes
// it to retrieve the answer.
void tokenize(char *input, char *answer);

// Displays the game results for each player, their name and final score, ranked
// from first to last place
void show_results(player *players, int num_players);

int main() {
  // An array of 4 players, may need to be a pointer if you want it set
  // dynamically
  player players[NUM_PLAYERS];

  // Input buffer and and commands
  char buffer[BUFFER_LEN] = {0};

  // Display the game introduction and initialize the questions
  initialize_game();

  // Prompt for players names
  // initialize each of the players in the array
  printf("Enter names: \n");
  for (int i = 0; i < NUM_PLAYERS; i++) {
    printf("Player %d: ", i + 1);
    printf("%s", fgets(buffer, BUFFER_LEN, stdin));
    strtok(buffer, "\n");
    if (player_exists(players, NUM_PLAYERS, buffer)) {
      printf("Player \"%s\" already exists. Please enter a new name.\n",
             buffer);
      i--;
    } else {
      strcpy(players[i].name, buffer);
      players[i].score = 0;
    }
  }
  printf("Press [Enter] to continue.");
  system("clear");

  char category[10];
  char dollarAmount[10];
  int player = 0;
  char result[BUFFER_LEN];
  int doneCounter = 0;
  // Perform an infinite loop getting command input from users until game ends
  while (fgets(buffer, BUFFER_LEN, stdin) != NULL) {
    do {
      // Call functions from the questions and players source files
      display_grid();
      player = player % NUM_PLAYERS;
      player++;
      printf("\n\nPlayer %d", player);
      printf("\n\nSelect a category.\n\n");
      for (int i = 0; i < NUM_CATEGORIES; i++)
        printf("[%d]: %s\n\n", i + 1, categories[i]);
      printf("Category: ");
      scanf("%s", category);
      if (strcmp(category, "1") != 0 && strcmp(category, "2") != 0 &&
          strcmp(category, "3") != 0) {
        printf("\nError: The number you entered is not a category number. "
               "Please enter a valid number.\n");
        player--;
      }
    } while ((strcmp(category, "1") != 0 && strcmp(category, "2") != 0 &&
              strcmp(category, "3") != 0));

    do {
      printf("\nSelect a Dollar Amount [100,200,300,400]. ");
      printf("\nDollar Amount: ");
      scanf("%s", dollarAmount);
      if (strcmp(dollarAmount, "100") != 0 &&
          strcmp(dollarAmount, "200") != 0 &&
          strcmp(dollarAmount, "300") != 0 &&
          strcmp(dollarAmount, "400") != 0) {
        printf("\nError: The number you entered is not a valid dollar amount. "
               "Please enter a valid number.\n");
      }
    } while (
        strcmp(dollarAmount, "100") != 0 && strcmp(dollarAmount, "200") != 0 &&
        strcmp(dollarAmount, "300") != 0 && strcmp(dollarAmount, "400") != 0);

    int dollars = atoi(dollarAmount);
    int cat = atoi(category);
    cat--;
    if (!already_answered(cat, dollars)) {

      display_question(cat, dollars);

      // Execute the game until all questions are answered

      printf("\nPlayer %d, what is your answer?\nAnswer: ", player);
      memset(buffer, 0, BUFFER_LEN);
      fflush(stdin);
      fgets(buffer, BUFFER_LEN, stdin);
      fgets(buffer, BUFFER_LEN, stdin);
      tokenize(buffer, result);
      bool var;
      var = valid_answer(cat, dollars, result);
      if (var) {
        update_score(players, player - 1, dollars);
      }
      memset(result, 0, BUFFER_LEN);
      // Current stnadings
      // Display the final results and exit
      doneCounter++;
      if (doneCounter == NUM_QUESTIONS) {
        show_results(players, NUM_PLAYERS);
        return EXIT_SUCCESS;
      } else {
        printf("Current Standings:\n");
        print_standings(players, NUM_PLAYERS);
      }
    } else {
      printf("That question has already been answered, please choose again!");
      player--;
      continue;
    }
  }
  return EXIT_SUCCESS;
}

void tokenize(char *input, char *answer) {
  const char delimiter[2] = " ";
  char *token = strtok(input, delimiter);
  if (token != NULL) {
    if (strcasecmp(token, "who") != 0 && strcasecmp(token, "what") != 0) {
      printf("Please enter your answer in the following form: what/who is/are "
             "[answer]\nAnswer: ");
      memset(input, 0, BUFFER_LEN);
      fflush(stdin);
      fgets(input, BUFFER_LEN, stdin);
      tokenize(input, input);
      strcpy(answer, token);
      // answer[strlen(answer) - 1] = '\0';
      return;
    }
  }

  if ((token = strtok(NULL, delimiter)) != NULL){
    if (strcmp(token, "is") != 0 && strcmp(token, "are") != 0) {
      strcpy(answer, token);
      answer[strlen(answer) - 1] = '\0';
      return;
    }
  }

  token = strtok(NULL, "\n");
  strcpy(answer, token);
}

void show_results(player *players, int num_players) {
  int max = 0;
  player standings[num_players];
  for (int i = 0; i < num_players; i++) {
    standings[i] = players[i];
  }
  printf(
      "\n________________________\n\nWOW, Good job!\n\n");
  for (int x = 0; x < num_players - 1; x++) {
    for (int i = 0; i < num_players - x - 1; i++) {
      if (standings[i].score < standings[i + 1].score) {
        player temp = standings[i];
        standings[i] = standings[i + 1];
        standings[i + 1] = temp;
      }
    }
  }
  for (int i = 0; i < num_players; i++) {
    printf("%d. %s\tScore: %d\n", i + 1, standings[i].name, standings[i].score);
  }
  printf("\nWinner: %s! Congratulations!\n", standings[0].name);
  printf("\n------------------------");
    printf("\n  GAME OVER - JEOPARDY");
    printf("\n------------------------\n");
    printf("\nThank you for playing!\n");
    printf("\nPlease come back soon!\n");
}
