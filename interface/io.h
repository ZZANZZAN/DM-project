/* Functions, that simplify IO */

#pragma once

#include <stdio.h>


/* FUNCTIONS */

void print(char *str);      /* Prints message to stderr */

char skip_spaces();         /* Skips space symbols in stdin */



/* FUNCTIONS IMPLEMENTATION */


void print(char *str) {
    
    fprintf(stderr, str);
}


char skip_spaces() {
    
    char symbol = getchar();
    
    while(!feof(stdin) && (symbol == ' ' || symbol == '\t'))
        symbol = getchar();
    
    return symbol;
}
