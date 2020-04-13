natural *Z5(integer *A)
{
    B = init_natural(A -> length);
    for(i = 0 ; i < B-> length ; i++) B -> dights[i] = A -> dights[i];
    return B;
}