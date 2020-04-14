// Nikolaenko
fraction *Q3(integer *A) {
        natural *B = init_natural(1);
        B -> digits[0] = 1;
        // conversion to rational
        fraction *R;
        R = init_fraction(A, B);
        
    return R;
}
