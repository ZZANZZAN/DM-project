// Nikolaenko and Kacer
natural *N5(natural *A, natural *B) {
    int q;
    // compare the numbers
    q = N1(A,B);

    if(q == 2){
        for(int i = 0; i < (B -> length); i++){
            if((A -> digits[i]) >= (B -> digits[i])) A -> digits[i] -= (B -> digits[i]); // subtraction
            else{ // take a ten
                int k = i + 1;
                while((A -> digits[k]) == 0) k++;
                
                A -> digits[k--] -= 1; // subtract one from whom we borrow
                while(k != i) A -> digits[k--] = 9; // if there are zeros between who is being borrowed and who is being borrowed for, then we replace them with nines
                
                A -> digits[i] += (10 - (B -> digits[i])); 
            } 
        }
        if(A -> digits[(A -> length) - 1] == 0) resize_natural(A, (A -> length) - 1);
    }else if(q == 1){
	    for(int i = 0; i < (A -> length); i++){
            if((B -> digits[i]) >= (A -> digits[i])) B -> digits[i] -= (A -> digits[i]); // subtraction
            else{ // take a ten
                int k = i + 1;
                while((B -> digits[k]) == 0) k++;
                
                B -> digits[k--] -= 1; // subtract one from whom we borrow
                while(k != i) B -> digits[k--] = 9; // if there are zeros between who is being borrowed and who is being borrowed for, then we replace them with nines
                
                B -> digits[i] += (10 - (A -> digits[i])); 
            } 
        } 
        if(B -> digits[(B -> length) - 1] == 0) resize_natural(B, (B -> length) - 1);
    }else if(q == 0){ // when the numbers are equal
    	A -> digits[0] = 0;
    	resize_natural(A, 1);
    	A -> length = 1;
	}
    
    if((q == 2) || (q == 0)) return A;
    else return B;
}
