// 9305_Nikolaenko

signed char N10(natural *A, natural *B) {
    natural *C, *D, *N;
    signed char t = 0;
	
    C = copy_natural(A);
    D = copy_natural(B);
     
     // compare
        int q = N1(A, B);
        
    // calculating the first digit
        if(q == 2) 
        {
            N = copy_natural(B);
            
            D = N7(D, 1);
            
            while((N1(C, D) == 2) || (N1(C, D) == 0)) 
			{
                D = N7(D, 1);
                N = N7(N, 1);
            }
            
            while((N1(C, N) == 2) || (N1(C, N) == 0))
			{
                C = N5(C, N);
                t++;
            }
        }
        else if(q == 1) t = 0;    
        else if(q == 0) t = 1;
        
    return t;
}
