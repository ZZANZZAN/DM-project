natural *N9(natural *A, natural *B, int c) {
    natural *C, *D, *R;
    size_t i;

    C = copy_natural(A);
    D = copy_natural(B);

          // compare
        int q = N1(A, B);

          // multiplication and subtraction
        if((q == 2) || (q == 0))
        {
            D = N6(D, c);
            C = N5(C, D);

            R = init_natural(C -> length);

            for(i = 0; i < (C -> length); i++)
                R -> digits[i] = (C -> digits[i]);
        }
		else R = copy_natural(A);
    free_natural(C);
    free_natural(D);
    return R;
}

