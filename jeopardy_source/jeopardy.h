/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U: Operating Systems
 * <Group Member:>
 * Darren E. Constantine - 100782701
 * Abdul Shahid - 100709858
 * Nived Leju Ramachandran Sonia - 100782317
 */
#include "players.h"
#ifndef JEOPARDY_H_
#define JEOPARDY_H_

#define MAX_LEN 256

// Processes the answer from the user containing what is or who is and tokenizes
// it to retrieve the answer.
extern void tokenize(char *input, char *answer);

// Displays the game results for each player, their name and final score, ranked
// from first to last place
extern void show_results(player *players, int num_players);

#endif /* JEOPARDY_H_ */