natural *N3(natural *A) 
{
	
	size_t i = 0;
	
	/* Skipping nines */
	
	while(i < (A -> length) && (A -> digits[i]) == 9)
		A -> digits[i++] = 0;
	
	if(i == (A -> length)) 
	{
		
		/* Increasing number length */
		
		resize_natural(A, (A -> length) + 1);
		
		A -> digits[(A -> length) - 1] = 1;
		
	} 
	else 
		++(A -> digits[i]);
	
	return A;
}
