polynomial *P3(polynomial *A, fraction *B)
{
	polynomial *res = NULL;
	fraction *temp = NULL;
	
	res = copy_polynomial(A);
	
	for (size_t i = 0; i <= A -> degree; i++)
	{
		temp = Q7 (A -> factors[i], B);
        
		free_fraction(res -> factors[i]);
        
        res -> factors[i] = temp;
	}
	
	free_fraction(temp);
	
	return res;
}
