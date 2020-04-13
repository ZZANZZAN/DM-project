natural *N3(natural *A)
{
size_t i;
    natural *res;
	res = init_natural(A -> length);
	for(i = 0 ; i < res -> length ; i++)
		res -> digits[i]  = A -> digits[i];
	/* Skipping nines */
	i = 0;
	while(i < (res -> length) && (res -> digits[i]) == 9)
		res -> digits[i++] = 0;
	if(i == (res -> length))
	{
		/* Increasing number length */
		resize_natural(res, (res -> length) + 1);
		res -> digits[(res -> length) - 1] = 1;
	}
	else
        ++(res -> digits[i]);
	return res;
}
