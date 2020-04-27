natural *N13(natural *A,natural *B)
{
    natural *first = NULL, *second = NULL, *temp = NULL;
    first = copy_natural(A);
    second = copy_natural(B);
    while(N2(first) && N2(second))
    {
        if(N1(first , second)==2)
        {
            temp = N12(first , second);
            free_natural(first);
            first = NULL;
            first = temp;
        }
        else
        {
            temp = N12(second , first);
            free_natural(second);
            second = NULL;
            second = temp;
        }
    }
    if(N2(first))
    {
        free_natural(second);
        return first;
    }
    else
    {
        free_natural(first);
        return second;
    }
}
