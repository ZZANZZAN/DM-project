#include <stdint.h>


int N1(natural *A, natural *B) {
    
    /* Compare length */
    
    if((A -> length) > (B -> length)) {
        
        return 2;
        
    } else if((A -> length) < (B -> length)) {
        
        return 1;
        
    } else {
        
        /* Digits comparison */
        
        for(size_t i = (A -> length) - 1; i != SIZE_MAX; --i) {
            
            if(A -> digits[i] > (B -> digits[i]))
                return 2;
                
            else if((A -> digits[i]) < (B -> digits[i]))
                return 1;
        }
        
        return 0;
    }
}
