natural *N6(natural *A, int b) {
	//checking for zero
	if(b){
		
	    size_t i = 0;
        int r = 0, c = 0;
	    //the main loop of the multiplication
	    while(i != (A -> length)){
            c = (A -> digits[i]) * b;
            if(r) c += r;   
            A -> digits[i] = c % 10;
            r = c / 10;
			i++;    
        }
        //case with a new category
        if(r){
            resize_natural(A, (A -> length) + 1);
            A -> digits[(A -> length) - 1] = r; 
        }
        
    }else{
    	//zeroing
    	A -> length = 1;
    	A -> digits[0] = 0;
	}
    
	return A;
}
