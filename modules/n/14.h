natural *N14(natural *A,natural *B)
{
    natural *first = NULL, *second = NULL, *res = NULL;
    first = copy_natural(A);
    second = copy_natural(B);
    res = N11(N8(first, second), N13(first, second)); //MUL_NN_N - Умножение нат. чисел, GCF_NN_N - их НОД
    free_natural(first);
    free_natural(second);
    return res;
}
