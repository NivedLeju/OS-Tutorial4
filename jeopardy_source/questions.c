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
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void){


    printf("     ____.                                   .___\n");
    printf("    |    | ____  ____ ___________ _______  __| _/__.__.\n");
    printf("    |    |/ __ \\/  _ \\\\____ \\__  \\\\_  __ \\/ __ <   |  |\n");
    printf("/\\__|    \\  ___(  <_> )  |_> > __ \\|  | \\/ /_/ |\\___  |\n");
    printf("\\________|\\___  >____/|   __(____  /__|  \\____ |/ ____|\n");
    printf("              \\/      |__|       \\/           \\/\\/     \n");
    // initialize each question struct and assign it to the questions array
    questions[0] = (question) { categories[0], "This language is used to design the basic structure of web pages.", "HTML", 100, false };
    questions[1] = (question) { categories[0], "Lines of code that are ignored by the compiler.", "Comments", 200, false };  
    questions[2] = (question) { categories[0], "A programming language that is converted into machine instructions without a compiler is called this.", "Interpreted", 300, false };
    questions[3] = (question) { categories[0], "This language was created by James Gosling and Sun Microsystems Inc starting in 1991.", "Java", 400, false };

    questions[4] = (question) { categories[1], "This type of search cuts the data set in half each time it fails to find the correct answer.", "Binary", 100, false };
    questions[5] = (question) { categories[1], "This type of function calls itself within its own code block.", "Recursive", 200, false };
    questions[6] = (question) { categories[1], "A non-comparative sorting algorithm that uses buckets and a positional number system.", "Radix", 300, false };
    questions[7] = (question) { categories[1], "The last name of the creator of the algorithm for finding the shortest paths between nodes in a weighted graph.", "Dijkstra", 400, false };

    questions[8] = (question) { categories[2], "This is what DBMS stands for.", "Database Management System", 100, false };
    questions[9] = (question) { categories[2], "The most popular type of database used today.", "Oracle", 200, false };
    questions[10] = (question) { categories[2], "A database that runs over the internet is said to reside here.", "Cloud", 300, false };
    questions[11] = (question) { categories[2], "The first commercial database language to use Edgar F Codd's relational model.", "SQL", 400, false };
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    
    // print categories and dollar values for each unanswered question in questions array
    // print category headings
    printf("-------------------------------------------\n");
    printf("| Programming | Algorithms  |  Databases  |\n");
    printf("-------------------------------------------\n");
    // two loops, one for each of the 4 rows, and another for each of the 3 columns
    int value;
    for (int i = 0; i < 4; i++) {
        value = i * 100 + 100;
        printf("|     ");
        for (int j = 0; j < 3; j++) {
            // if question not already answered, print the value, otherwise print ---
            if (!already_answered(categories[j], value))
                printf("%d", value);
            else
                printf("---");
            printf("     |     ");
        }
        printf("\n");
    }
    printf("-------------------------------------------\n");
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
    // find the question number
    int num;
    for (int i = 0; i < 12; i += 4) {
        if (strcmp(questions[i].category, category) == 0) {
            num = i + (value / 100) - 1;
        }
    }
    // print the question
    printf("Question for category %s, value %d:\n");
    printf("%s", questions[num].question);
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
    for(int i = 0; i < NUM_QUESTIONS; i++){
        // if(){

        // }
    }
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    int num;
    for (int i = 0; i < 12; i += 4) {
        if (strcmp(questions[i].category, category) == 0) {
            num = i + (value / 100) - 1;
        }
    }
    return questions[num].answered;
}
