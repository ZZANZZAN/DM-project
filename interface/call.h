/* Reads numbers and calls modules */

#pragma once

#include "../config.h"
#include "call/n.h"
#include "call/z.h"
#include "call/q.h"
#include "call/p.h"


/* FUNCTIONS */

unsigned char call(char block, unsigned char n);    /* Reads needed data and calls module */



/* FUNCTIONS IMPLEMENTATIONS */


unsigned char call(char block, unsigned char n) {
    
    if(block == 'N') {
        
        return call_N(n);
    
    } else if(block == 'Z') {
        
        return call_Z(n);
        
    } else if(block == 'Q') {
        
        return call_Q(n);
        
    /*
    } else if(block == 'P') {
        
        return call_P(n);
    */
    
    } else return RCODE_NF;
}
