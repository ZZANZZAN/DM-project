/* Functions, that simplify IO */

#pragma once

#include <stdio.h>


/* FUNCTIONS */

void print(const char *str);      /* Prints message to stderr */

char skip_spaces();         /* Skips space symbols in stdin */



/* FUNCTIONS IMPLEMENTATION */


void print(const char *str) {
    
    fprintf(stderr, str);
}


char skip_spaces() {
    
    char symbol = getchar();
    
    while(!feof(stdin) && (symbol == ' ' || symbol == '\t'))
        symbol = getchar();
    
    return symbol;
}
