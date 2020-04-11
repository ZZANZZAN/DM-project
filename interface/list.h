/* Prints list with available modules */

#pragma once

#include "locale.h"
#include "io.h"
#include "../config.h"


/* FUNCTIONS */

void list();        /* Prints pre-generated list */



/* FUNCTIONS IMPLEMENTATIONS */


void list() {
    
    print(LIST_TITLE "\n\n");
    
    /* Block N */
    
    print(BLOCK_N "\n\n");
    
    #ifdef N_1
        print(N_1_DESCR "\n");
    #endif
    
    #ifdef N_2
        print(N_2_DESCR "\n");
    #endif
    
    #ifdef N_3
        print(N_3_DESCR "\n");
    #endif
    
    #ifdef N_4
        print(N_4_DESCR "\n");
    #endif
    
    #ifdef N_5
        print(N_5_DESCR "\n");
    #endif
    
    #ifdef N_6
        print(N_6_DESCR "\n");
    #endif
    
    #ifdef N_7
        print(N_7_DESCR "\n");
    #endif
    
    #ifdef N_8
        print(N_8_DESCR "\n");
    #endif
    
    #ifdef N_9
        print(N_9_DESCR "\n");
    #endif
    
    #ifdef N_10
        print(N_10_DESCR "\n");
    #endif
    
    #ifdef N_11
        print(N_11_DESCR "\n");
    #endif
    
    #ifdef N_12
        print(N_12_DESCR "\n");
    #endif
    
    #ifdef N_13
        print(N_13_DESCR "\n");
    #endif
    
    #ifdef N_14
        print(N_14_DESCR "\n");
    #endif
    
    
    /* Block Z */
    
    print("\n" BLOCK_Z "\n\n");
    
    #ifdef Z_1
        print(Z_1_DESCR "\n");
    #endif
    
    #ifdef Z_2
        print(Z_2_DESCR "\n");
    #endif
    
    #ifdef Z_3
        print(Z_3_DESCR "\n");
    #endif
    
    #ifdef Z_4
        print(Z_4_DESCR "\n");
    #endif
    
    #ifdef Z_5
        print(Z_5_DESCR "\n");
    #endif
    
    #ifdef Z_6
        print(Z_6_DESCR "\n");
    #endif
    
    #ifdef Z_7
        print(Z_7_DESCR "\n");
    #endif
    
    #ifdef Z_8
        print(Z_8_DESCR "\n");
    #endif
    
    #ifdef Z_9
        print(Z_9_DESCR "\n");
    #endif
    
    #ifdef Z_10
        print(Z_10_DESCR "\n");
    #endif
    
    
    /* Block Q */
    
    // print("\n" BLOCK_Q "\n\n");
    
    #ifdef Q_1
        print(Q_1_DESCR "\n");
    #endif
    
    #ifdef Q_2
        print(Q_2_DESCR "\n");
    #endif
    
    #ifdef Q_3
        print(Q_3_DESCR "\n");
    #endif
    
    #ifdef Q_4
        print(Q_4_DESCR "\n");
    #endif
    
    #ifdef Q_5
        print(Q_5_DESCR "\n");
    #endif
    
    #ifdef Q_6
        print(Q_6_DESCR "\n");
    #endif
    
    #ifdef Q_7
        print(Q_7_DESCR "\n");
    #endif
    
    #ifdef Q_8
        print(Q_8_DESCR "\n");
    #endif
    
    
    /* Block P */
    
    // print("\n" BLOCK_P "\n\n");
    
    #ifdef P_1
        print(P_1_DESCR "\n");
    #endif
    
    #ifdef P_2
        print(P_2_DESCR "\n");
    #endif
    
    #ifdef P_3
        print(P_3_DESCR "\n");
    #endif
    
    #ifdef P_4
        print(P_4_DESCR "\n");
    #endif
    
    #ifdef P_5
        print(P_5_DESCR "\n");
    #endif
    
    #ifdef P_6
        print(P_6_DESCR "\n");
    #endif
    
    #ifdef P_7
        print(P_7_DESCR "\n");
    #endif
    
    #ifdef P_8
        print(P_8_DESCR "\n");
    #endif
    
    #ifdef P_9
        print(P_9_DESCR "\n");
    #endif
    
    #ifdef P_10
        print(P_10_DESCR "\n");
    #endif
    
    #ifdef P_11
        print(P_11_DESCR "\n");
    #endif
    
    #ifdef P_12
        print(P_12_DESCR "\n");
    #endif
    
    #ifdef P_13
        print(P_13_DESCR "\n");
    #endif
}
