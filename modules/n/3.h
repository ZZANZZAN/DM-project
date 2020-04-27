natural *N3(natural *A)
{
    natural *res;
	res = copy_natural(A);
	size_t i = 0;
	while(i < (res -> length) && (res -> digits[i]) == 9)
		res -> digits[i++] = 0;
    // Increasing number length
	if(i == (res -> length))
	{
		resize_natural(res, (res -> length) + 1);
		res -> digits[(res -> length) - 1] = 1;
	}
	else
        ++(res -> digits[i]);
	return res;
}
