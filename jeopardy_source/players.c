/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U: Operating Systems
 * <Group Member:>
 * Darren E. Constantine - 100782701
 * Abdul Shahid - 100709858
 * Nived Leju Ramachandran Sonia - 100782317
 */
#include "players.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Returns true if the player name matches one of the existing players
bool player_exists(player *players, int num_players, char *name) {
  for (int i = 0; i < num_players; i++) {
    if (strcmp(players[i].name, name) == 0) {
      return true;
    }
  }

  return false;
}

// Go through the list of players and update the score for the
// player given their name
void update_score(player *players, int player, int score) {
  players[player].score += score;
}

void print_standings(player *players, int num_players) {
  int max = 0;
  player standings[num_players];
  for (int i = 0; i < num_players; i++) {
    standings[i] = players[i];
  }

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
    printf("%d. %s\tScore: %d\n", i + 1, standings[i].name,
           standings[i].score);
  }
  printf("\n\nPress [Enter] to continue.");
}
