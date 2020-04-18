fraction *Q1(fraction *A) {
    fraction *res = copy_fraction(A);
    res -> numerator = Z9(A -> numerator, Z4(N13(A -> denominator, Z1(A -> numerator))));
    res -> denominator = N11(A -> denominator, N13(A -> denominator, Z1(A -> numerator)));
    return res;
}
