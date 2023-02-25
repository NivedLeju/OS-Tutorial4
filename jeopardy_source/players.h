/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U: Operating Systems
 * <Group Member:>
 * Darren E. Constantine - 100782701
 * Abdul Shahid - 100709858
 * Nived Leju Ramachandran Sonia - 100782317
 */
#ifndef PLAYERS_H_
#define PLAYERS_H_

#include <stdbool.h>

#define MAX_LEN 256

// Player struct for each player
typedef struct {
  char *name[MAX_LEN];
  int score;
} player;

// Returns true if the player name matches one of the existing players
extern bool player_exists(player *players, int num_players, char *name);

// Go through the list of players and update the score for the
// player given their name
extern void update_score(player *players, int num_players,
                         int score);
// Displays standings
extern void print_standings(player *players, int num_players);
#endif /* PLAYERS_H_ */