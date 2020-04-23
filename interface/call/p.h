/* Wrappers for Q block modules */

#pragma once

#include "../io.h"
#include "../numbers.h"
#include "../locale.h"
#include "../include.h"


/* FUNCTIONS */

unsigned char call_P(unsigned char n);      /* Block N wrappers */



/* FUNCTIONS IMPLEMENTATIONS */


unsigned char call_P(unsigned char n) {
        
    switch(n) {
        
        
        
        default: return RCODE_NF;
    }
    
    print("\n");
    
    return RCODE_OK;
}
