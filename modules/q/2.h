// 9305_Nikolaenko
#include <stdbool.h>

bool Q2(fraction *A) {
    
    if(((A -> denominator -> length) == 1) && (A -> denominator -> digits[0] == 1)) 
	{
		return true;
	}
    else
    {
    	natural *B, *C;
    	
        B = init_natural(A -> numerator -> length);
        for(size_t j = 0; j < (B -> length); j++) B -> digits[j] = (A -> numerator -> digits[j]);
        C = copy_natural(A -> denominator);
    
        if(N1(B, C) == 0) return true;
        else
		{    	
			natural *F;
			F = N13(B, C);
			
			if(N1(F, C) == 0) return true;
			else return false;
		} 
    }
}
