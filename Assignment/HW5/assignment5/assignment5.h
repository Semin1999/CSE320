/*
* File: assignment5.h
* Owner: Semin Bae (114730530) / semin.bae@stonybrook.edu
* Date: 11.9.2024
* Description: Implementing a shell program in C
*/
#ifndef ASSIGNMENT5
#define ASSIGNMENT5

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

void command_line_parse(char *input, char *command, char **arguments);
void command_line_execute(char *command, char **arguments);

#endif
