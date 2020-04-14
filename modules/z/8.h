integer *Z8(integer *A, integer *B) {
    integer *R;
  
    int q = Z2(A);
    int f = Z2(B);

    if((q) && (f))
    {
        natural *C, *D;
        C = Z1(A);
        D = Z1(B);
        C = N8(C,D);
        R = init_integer(C -> length);
        for(int i = 0; i < (C -> length); i++) 
            R -> digits[i] = (C -> digits[i]);
        R -> sign = true;
        if(((q == 1) && (f == 2)) || ((q == 2) && (f == 1))) R = Z3(R);
    }
    else
    {
        R = init_integer(1);
        R -> digits[0] = 0;
        R -> sign = true; 
    }    

    return R;
}
