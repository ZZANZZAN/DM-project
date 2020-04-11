/* Command line interface */

#pragma once

#include <stdbool.h>
#include <ctype.h>

#include "io.h"
#include "locale.h"
#include "system.h"
#include "list.h"
#include "call.h"


/* STRUCTURES */

typedef struct {
    
    char block;
    unsigned char arg;
    
} command;


/* FUNCTIONS */

void interface();                           /* Runs command line interface */

unsigned char read_cmd(command *cmd);       /* Reads command. Returns code */



/* FUNCTIONS IMPLEMENTATION */


unsigned char read_cmd(command *cmd) {
    
    char current = skip_spaces();   /* Reading first non-space symbol */
    
    /* Handling first symbol */
    
    if(feof(stdin)) {
        
        print(UNEXP_EOF "\n");
        terminate(RCODE_EOF);
    }
    
    if(current == '\n') return RCODE_EMPTY;
    
    cmd -> block = toupper(current);    /* Setting block */
    cmd -> arg = 0;                     /* Resetting argument */
    
    current = getchar();
    
    /* Read up to the newline */
    
    while(!feof(stdin) && current != '\n') {
        
        if(isdigit(current) && (cmd -> arg) < 10) {
            
            /* Update argument */
            
            cmd -> arg *= 10;
            cmd -> arg += current - '0';
            
            current = getchar();
            
        } else if(current == '-' || current == ' ' || current == '\t') {
            
            current = getchar();
            
        } else {
            
            /* Unexpected symbol */
            
            while(!feof(stdin) && current != '\n')
                current = getchar();
            
            return RCODE_UNEXP;
        }
    }
    
    return RCODE_OK;
}


void interface() {
    
    bool work;              /* Infinite cycle flag */
    command cmd;            /* Command argument */
    unsigned char result;   /* Result of function execution */
    
    /* Greeting */
    
    print(TITLE "\n\n");
    
    print(USAGE "\n");
    
    
    /* Infinite command cycle */
    
    work = true;
    
    while(work) {
        
        print(CMD_WAIT);
        
        /* Reading command */
        
        result = read_cmd(&cmd);
        
        /* Handling */
        
        if(result == RCODE_OK) {
            
            switch(cmd.block) {
                case 'L': list(); break;
                case 'E': terminate(RCODE_OK); break;
                default: if(call(cmd.block, cmd.arg) == RCODE_NF) print(UNKN_CMD "\n\n"); break;
            }
            
        } else if(result == RCODE_UNEXP) {
            
            print(UNEXP_SYMBOL "\n\n");
            
        } else if(result != RCODE_EMPTY) terminate(RCODE_UNKN);
    }
}
