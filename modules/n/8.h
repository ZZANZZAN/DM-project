natural *N8(natural *A, natural *B)
{
    natural *res;
    natural *temp;
    size_t i , temp_length;
    res = init_natural(1);
    res -> digits[0] = 0;
    if (A -> length > B -> length)
    {
        temp_length = B -> length;
        for (i = 0 ; i < temp_length; i++)
        {
            temp = N6 (A, B -> digits[i]);
            temp = N7 (temp , i);
            res = N4 (temp , res);
            free_natural(temp);
        }
    }
    else
    {
        temp_length = A -> length;
        for (i = 0 ; i < temp_length ; i++)
        {
        	temp = N6 (B , A -> digits[i]);
            temp = N7 (temp , i);
        	res = N4 (temp , res);
            free_natural(temp);
        }
    }
    return res;
}
