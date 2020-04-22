natural *N8(natural *A, natural *B)
{
    natural *res;
    natural *temp;
    natural *t;
    size_t i , temp_length;
    res = init_natural(1);
    res -> digits[0] = 0;
    if (A -> length > B -> length)
    {
        temp_length = B -> length;
        for (i = 0 ; i < temp_length; i++)
        {
            temp = N6 (A, B -> digits[i]);
            t = temp;
            temp = N7 (temp , i);
            free_natural(t);
            t = res;
            res = N4 (temp , res);
            free_natural(t);
            free_natural(temp);
        }
    }
    else
    {
        temp_length = A -> length;
        for (i = 0 ; i < temp_length ; i++)
        {
        	temp = N6 (B , A -> digits[i]);
            t = temp;
            temp = N7 (temp , i);
            free_natural(t);
            t = res;
            res = N4 (temp , res);
            free_natural(t);
            free_natural(temp);
        }
    }
    return res;
}
