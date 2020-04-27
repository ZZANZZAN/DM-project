fraction *Q8(fraction *A, fraction *B) {
    integer *C, *D, *tempInt;
    natural *tempNat;
    size_t i;

    C = init_integer(A -> numerator -> length);
    C -> sign = (A -> numerator -> sign);
    for(i = 0; i < (C -> length); i++)
        C -> digits[i] = (A -> numerator ->digits[i]);

    D = init_integer(B -> denominator -> length);
    D -> sign = true;
    for(i = 0; i < (D -> length); i++)
        D -> digits[i] = (B -> denominator ->digits[i]);
    tempInt=C;
    C = Z8(C, D);
    free_integer(tempInt);

        integer *N, *P;

        N = init_integer(B -> numerator -> length);
        N -> sign = (B -> numerator -> sign);
        for(i = 0; i < (N -> length); i++)
            N -> digits[i] = (B -> numerator ->digits[i]);

        P = init_integer(A -> denominator -> length);
        P -> sign = true;
        for(i = 0; i < (P -> length); i++)
            P -> digits[i] = (A -> denominator ->digits[i]);
        tempInt=P;
        P = Z8(N, P);
        free_integer(tempInt);

        if((P -> sign) == false) C = Z3(C);

        natural *G = init_natural(P -> length);
        for(i = 0; i < (G -> length); i++)
            G -> digits[i] = (P -> digits[i]);

	natural *K = init_natural(C -> length);
	for(size_t j = 0; j < (C -> length); j++) K -> digits[j] = C -> digits[j];

	natural *F = N13(K, G);
	tempNat=K;
	K = N11(K, F);
	free_natural(tempNat);
	tempNat=G;
	G = N11(G, F);
	free_natural(tempNat);

	C -> length =  K -> length;
	for(size_t j = 0; j < (K -> length); j++) C -> digits[j] = K -> digits[j];

	fraction *R = init_fraction(C, G);
    free_natural(G);
    free_natural(K);
    free_natural(F);
    free_integer(P);
    free_integer(C);
    free_integer(N);
    free_integer(D);

    return R;
}
