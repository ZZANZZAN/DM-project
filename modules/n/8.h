natural *N8(natural *A, natural *B)
{
    natural *res = NULL, *temp = NULL, *t = NULL;
    size_t i;
    res = init_natural(1);
    res -> digits[0] = 0;
    if (A -> length > B -> length)
    {
        for (i = 0 ; i < B -> length; i++)
        {
            temp = N6 (A , B -> digits[i]);
            t = temp;
            free_natural(temp);
            temp = N7 (t , i);
            free_natural(t);
            t = res;
            free_natural(res);
            res = N4 (temp , t);
            free_natural(t);
            free_natural(temp);
        }
    }
    else
    {
        for (i = 0 ; i < A -> length ; i++)
        {
        	temp = N6 (B , A -> digits[i]);
            t = temp;
            free_natural(temp);
            temp = N7 (t , i);
            free_natural(t);
            t = res;
            free_natural(res);
            res = N4 (temp , t);
            free_natural(t);
            free_natural(temp);
        }
    }
    return res;
}
