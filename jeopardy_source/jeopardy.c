/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here
extern question questions[NUM_QUESTIONS];
// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);


int main()
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names
    // initialize each of the players in the array
    printf("Enter names: \n");
    for (int i = 0; i < NUM_PLAYERS; i++){
        printf("Player %d", i);
        fgets(buffer, BUFFER_LEN, stdin);
        strtok(buffer, "\n");
        if (player_exists(players, NUM_PLAYERS, buffer)){
            printf("Player \"%s\" already exists. Please enter a new name.", buffer);
            i--;
        }
        else{
            strcpy(players[i].name, buffer);
            players[i].score = 0;
        }
    }
    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Call functions from the questions and players source files
        // Execute the game until all questions are answered
        char answer[BUFFER_LEN];
        // some more code, and then:
        tokenize(buffer, answer);
        // Display the final results and exit
                
    }

    
    show_results(players, NUM_PLAYERS);
    return EXIT_SUCCESS;
}

void tokenize(char *input, char *answer) {
    const char delimiter[2] = " ";
    char *token = strtok(input, delimiter);
    if(token!= NULL)
        if(strcmp(token, "who") != 0 && strcmp(token, "what") != 0)
            return;

    if((token = strtok(NULL, delimiter)) != NULL)
        if(strcmp(token, "is") != 0)
            return;

    token = strtok(NULL, "\n");
    strcpy(answer, token);
}

void show_results(player *players, int num_players) {
    int name = 0;
    int score = 0;
    int winner = 0;

    for(int i = 0; i < num_players; i++) {
        if((int) strlen((const char*)players[i].name) > name)
            name = strlen(*players[i].name);

        if(players[i].score > score) {
            score = players[i].score;
            winner = i;
        }
    }

    printf("Scores: \n");
    for(int i = 0; i < num_players; i++)
        printf("%-*s: %d\n", name, *players[i].name, players[i].score);

    printf("Winner: %s", *players[winner].name);
    
}
