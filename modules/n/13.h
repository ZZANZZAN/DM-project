natural *N13(natural *A,natural *B)
{
    natural *first = NULL, *second = NULL;
    first = copy_natural(A);
    second = copy_natural(B);
    while(N2(first) && N2(second))
    {
        if(N1(first , second)==2)
        {
            first = N12(first , second);
        }
        else
        {
           second = N12(second , first);
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
