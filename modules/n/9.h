// Nikolaenko
natural *N9(natural *A, natural *B, int c) {
    natural *C, *D, *R;
    size_t i;
	
    C = init_natural(A -> length);
    D = init_natural(B -> length);
    
    C -> length = A -> length;
    D -> length = B -> length;
    
    for(i = 0; i < (C -> length); i++) 
	    C -> digits[i] = (A -> digits[i]);
    for(i = 0; i < (D -> length); i++) 
	    D -> digits[i] = (B -> digits[i]);
          // compare
        int q = N1(A, B);
          // multiplication and subtraction      
        if((q == 2) || (q == 0)) 
        {
            D = N6(D, c);
            C = N5(C, D);
            R = init_natural(C -> length);
            for(i = 0; i < (C -> length); i++) 
                R -> digits[i] = (C -> digits[i]);
        }
        else if(q == 1) 
        {    
            C = N6(C, c);
            D = N5(D, C);
            R = init_natural(D -> length);
            for(i = 0; i < (D -> length); i++) 
                R -> digits[i] = (D -> digits[i]);
        }    
        
    return R;
}
