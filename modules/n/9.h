natural *N9(natural *A, natural *B, int c)
{
    natural *C = NULL, *res = NULL;
    C = N6 (B , c);
    res = N5 (A , C);
    free_natural(C);
    return res;
}
