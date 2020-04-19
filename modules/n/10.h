// 9305_Nikolaenko

signed char N10(natural *A, natural *B) {
    natural *C, *D, *N;
    size_t i;
    signed char t = 0;
	
    C = copy_natural(A);
    D = copy_natural(B);
     
     // compare
        int q = N1(A, B);
        
    // calculating the first digit
        if(q == 2) 
        {
            N = init_natural(B -> length);
            N = init_natural(B -> length);
           
		    for(i = 0; i < (N -> length); i++) 
	            N -> digits[i] = (B -> digits[i]);
            
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
=======
natural *N10(natural *A, natural *B) {
    natural *Result, *n_10, *temp;
    size_t flag, i, length;
    int result, m, a, b;
    length = 0;
    natural *dividend, *divider;
    if (N1(A, B) == 2) {
        dividend = copy_natural(A);
        divider = copy_natural(B);

    } else {
        dividend = copy_natural(B);
        divider = copy_natural(A);
    }
    /*finding a larger*/
    flag = N1(A, B);

    if (!flag)
        result = 1;
    else if (flag == 2) {
        a = A->digits[A->length - 1];
        b = B->digits[B->length - 1];
        m = 0;

        /*if the first digit is smaller, increase it*/
        if (a < b) {
            m = 1;
            a = a * 10 + A->digits[A->length - 2];
        }

        /*counting numbers*/
        for (i = 1; i < B->length; i++) {
            a = a * 10 + A->digits[A->length - 1 - m - i];
            b = b * 10 + B->digits[B->length - 1 - i];
        }
        result = a / b;
    } else {
        a = A->digits[A->length - 1];
        b = B->digits[B->length - 1];
        m = 0;

        /*if the first digit is smaller, increase it*/
        if (b < a) {
            m = 1;
            b = b * 10 + B->digits[B->length - 2];
        }

        /*counting numbers*/
        for (i = 1; i < A->length; i++) {
            a = a * 10 + A->digits[A->length - 1 - i];
            b = b * 10 + B->digits[B->length - 1 - m - i];
        }

        result = b / a;
    }
    n_10 = init_natural(2);
    n_10->digits[0] = 0;
    n_10->digits[1] = 1;
    Result = init_natural(1);
    Result->digits[0] = result;
    while (N1(N8(Result, divider), dividend) != 2) {
        temp = Result;
        Result = N8(n_10, Result);
        free_natural(temp);
        length++;
    }
    length--;
    free_natural(Result);
    Result = init_natural(1);
    Result->digits[0] = result;
    temp=Result;
    Result=N7(Result,length);
    free_natural(temp);
    free_natural(dividend);
    free_natural(divider);

    return Result;
}