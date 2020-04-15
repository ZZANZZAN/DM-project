integer *Z6(integer *A, integer *B)
{
    int k1, k2;
    integer *R;
    natural *aN, *bN, *L;
    k1 = Z2(A);
    k2 = Z2(B);
    aN = Z1(A);
    bN = Z1(B);
    R = init_integer(aN -> length);
    R = init_integer(bN -> length);
    R = NULL;

    if ((k1 == 2) && (k2 == 2)) {
        L = N4(aN, bN);
        R = init_integer(L -> length);
        R = Z4(L);
        R -> sign = true;
    }
    else if ((k1 == 1) && (k2 == 1)) {
        L = N4(aN, bN);
        R = init_integer(L -> length);
        R = Z4(L);
        R -> sign = false;
    }
    else if ((k1 == 2) && (k2 == 1)) {
        if ((N1(aN, bN) == 2) || (N1(aN, bN) == 0)) {
            R = Z4(N5(aN, bN));
            R -> sign = true;
        }
        else if (N1(aN, bN) == 1) {
            R = Z4(N5(bN, aN));
            R -> sign = false;
        }
    }
    else if ((k1 == 1) && (k2 == 2)) {
        if (N1(aN, bN) == 2) {
            R = Z4(N5(aN, bN));
            R -> sign = false;
        }
        else if ((N1(aN, bN) == 1) || (N1(aN, bN) == 0)) {
            R = Z4(N5(bN, aN));
            R -> sign = true;
        }
    }
    else if (k1 == 0) {
        if (k2 == 2) {
            B -> sign = true;
        }
        else if (k2 == 1) {
            B -> sign = false;
        }
        R = init_integer(B -> length);
        R = B;
    }
    else if (k2 == 0) {
        if (k1 == 2) {
            A -> sign = true;
        }
        else if (k1 == 1) {
            A -> sign = false;
        }
        R = init_integer(A -> length);
        R = A;
    }
    return(R);
}

