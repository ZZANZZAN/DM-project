/* Wrappers for N block modules */

#pragma once

#include "../io.h"
#include "../numbers.h"
#include "../locale.h"
#include "../include.h"


/* FUNCTIONS */

unsigned char call_N(unsigned char n);      /* Block N wrappers */



/* FUNCTIONS IMPLEMENTATIONS */


unsigned char call_N(unsigned char n) {
        
    switch(n) {
        #ifdef N_1
            case 1:
            {
                natural *A = read_natural(FIRST_ARG_LN);
                natural *B = read_natural(SECOND_ARG_LN);
                int result = N1(A, B);
                
                print("\n" RESULT);
                write_int(result);
    
                free_natural(A);
                free_natural(B);
                
                break;
            }
        #endif
        
        #ifdef N_2
            case 2:
            {
                natural *A = read_natural(FIRST_ARG_LN);
                bool result = N2(A);
                
                print("\n" RESULT);
                write_bool(result);
                
                free_natural(A);
                
                break;
            }
        #endif
        
        #ifdef N_3
            case 3:
            {
                natural *A = read_natural(FIRST_ARG_LN);
                natural *result = N3(A);
                
                print("\n" RESULT);
                write_natural(result);
                
                free_natural(A);
                free_natural(result);
                
                break;
            }
        #endif
        
        #ifdef N_4
            case 4:
            {
                natural *A = read_natural(FIRST_ARG_LN);
                natural *B = read_natural(SECOND_ARG_LN);
                natural *result = N4(A, B);
                
                print("\n" RESULT);
                write_natural(result);
                
                free_natural(A);
                free_natural(B);
                free_natural(result);
                
                break;
            }
        #endif
        
        #ifdef N_5
            case 5:
            {
                natural *A = read_natural(FIRST_ARG_LN);
                natural *B = read_natural(SECOND_ARG_LN);
                natural *result = N5(A, B);
                
                print("\n" RESULT);
                write_natural(result);
                
                free_natural(A);
                free_natural(B);
                free_natural(result);
                
                break;
            }
        #endif
        
        #ifdef N_6
            case 6:
            {
                natural *A = read_natural(FIRST_ARG_LN);
                int b = read_int(SECOND_ARG_INT);
                natural *result = N6(A, b);
                
                print("\n" RESULT);
                write_natural(result);
                
                free_natural(A);
                free_natural(result);
                
                break;
            }
        #endif
        
        #ifdef N_7
            case 7:
            {
                natural *A = read_natural(FIRST_ARG_LN);
                int b = read_int(SECOND_ARG_INT);
                natural *result = N7(A, b);
                
                print("\n" RESULT);
                write_natural(result);
                
                free_natural(A);
                free_natural(result);
                
                break;
            }
        #endif
        
        #ifdef N_8
            case 8:
            {
                natural *A = read_natural(FIRST_ARG_LN);
                natural *B = read_natural(SECOND_ARG_LN);
                natural *result = N8(A, B);
                
                print("\n" RESULT);
                write_natural(result);
                
                free_natural(A);
                free_natural(B);
                free_natural(result);
                
                break;
            }
        #endif
        
        #ifdef N_11
            case 11:
            {
                natural *A = read_natural(FIRST_ARG_LN);
                natural *B = read_natural(SECOND_ARG_LN);
                natural *result = N11(A, B);
                
                print("\n" RESULT);
                write_natural(result);
                
                free_natural(A);
                free_natural(B);
                free_natural(result);
                
                break;
            }
        #endif
        
        #ifdef N_12
            case 12:
            {
                natural *A = read_natural(FIRST_ARG_LN);
                natural *B = read_natural(SECOND_ARG_LN);
                natural *result = N12(A, B);
                
                print("\n" RESULT);
                write_natural(result);
                
                free_natural(A);
                free_natural(B);
                free_natural(result);
                
                break;
            }
        #endif
        
        #ifdef N_13
            case 13:
            {
                natural *A = read_natural(FIRST_ARG_LN);
                natural *B = read_natural(SECOND_ARG_LN);
                natural *result = N13(A, B);
                
                print("\n" RESULT);
                write_natural(result);
                
                free_natural(A);
                free_natural(result);
                
                break;
            }
        #endif
        
        #ifdef N_14
            case 14:
            {
                natural *A = read_natural(FIRST_ARG_LN);
                natural *B = read_natural(SECOND_ARG_LN);
                natural *result = N14(A, B);
                
                print("\n" RESULT);
                write_natural(result);
                
                free_natural(A);
                free_natural(B);
                free_natural(result);
                
                break;
            }
        #endif
        
        default: return RCODE_NF;
    }
    
    print("\n");
    
    return RCODE_OK;
}
