natural *N14(natural *A,natural *B)
{
    natural *first = NULL, *second = NULL, *res = NULL, *temp1 = NULL, *temp2 = NULL;
    first = copy_natural (A);
    second = copy_natural (B);
    temp1 = N8 (first, second);
    temp2 = N13 (first, second);
    res = N11 (temp1, temp2);
    free_natural(temp1);
    free_natural(temp2);
    free_natural(first);
    free_natural(second);
    return res;
}
