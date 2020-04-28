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
        #ifdef P_1
            case 1:
            {
                
                polynomial *A = read_polynomial(FIRST_POLY);
                polynomial *B = read_polynomial(SECOND_POLY);
                polynomial *result = P1(A, B);
                
                print("\n" RESULT);
                write_polynomial(result);
                
                free_polynomial(A);
                free_polynomial(B);
                free_polynomial(result);
                
                break;
            }
        #endif
        
        #ifdef P_6
            case 6:
            {
                polynomial *A = read_polynomial(FIRST_POLY);
                size_t result = P6(A);
                
                print("\n" RESULT);
                write_int((int)result);
                
                free_polynomial(A);
                
                break;
            }
        #endif
        
        default: return RCODE_NF;
    }
    
    print("\n");
    
    return RCODE_OK;
}
