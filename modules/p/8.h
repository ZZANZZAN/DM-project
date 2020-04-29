integer *Z8(integer *A, integer *B) {
    integer *R;
  
    int q = Z2(A);
    int f = Z2(B);

    if((q) && (f))
    {
        natural *C, *D, *N;
        //берем абсолютные величины
		C = Z1(A);
        D = Z1(B);
        //перемножаем их
		N = N8(C,D);
        
		R = init_integer(N -> length);
        //записываем в результат
		for(size_t i = 0; i < (N -> length); i++) 
            R -> digits[i] = (N -> digits[i]);
        
		R -> sign = true;
        
		free_natural(C);
		free_natural(D);
		free_natural(N);
		
		if(((q == 1) && (f == 2)) || ((q == 2) && (f == 1))){
			if(R -> sign == true) R -> sign = false;
			else R -> sign = true;
		}
    }
    else
    {
        R = init_integer(1);
        R -> digits[0] = 0;
        R -> sign = true; 
    }    

    return R;
}
