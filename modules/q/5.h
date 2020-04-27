fraction *Q5(fraction *A, fraction *B) {
    fraction *R = NULL, *R1 = NULL;
    natural *N = NULL;
    integer *C = NULL, *D = NULL, *ResChisl = NULL, *tempA = NULL, *tempB = NULL;

    tempA = Z4(A->denominator);
    tempB = Z4(B->denominator);
    N = N8(A->denominator, B->denominator);//новый знаменатель
    C = Z8(A->numerator, tempB);//новый числитель первой дроби
    D = Z8(B->numerator, tempA);//новый числитель второй дроби
    ResChisl = Z6(C, D);// сложение новых числителей

    R = init_fraction(ResChisl, N); //составление новой дроби
    R1 = Q1(R); // сокращение новой дроби

    //очистка
    free_natural(N);
    N = NULL;
    free_integer(ResChisl);
    ResChisl = NULL;
    free_integer(C);
    C = NULL;
    free_integer(D);
    D = NULL;
    free_fraction(R);
    R = NULL;
    free_integer(tempA);
    free_integer(tempB);

    return R1;
}
