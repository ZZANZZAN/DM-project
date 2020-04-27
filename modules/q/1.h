fraction *Q1(fraction *A)
{
    fraction *res = copy_fraction(A);
    natural *B = NULL;
    int sign = 1;
    integer *temp1=NULL;
    natural* temp_numerator = Z1(A -> numerator), * temp_denominator = res->denominator , *temp2 = NULL;
    B = N13(A -> denominator, temp_numerator);

    free_natural(temp_numerator);
    temp2 = Z1(A->numerator);
    sign = Z2(A->numerator);
    temp1 = res->numerator;
    temp_numerator = N11(temp2, B);

    res->numerator=Z4(temp_numerator);

    free_natural(temp_numerator);
    free_integer(temp1);
    free_natural(temp2);

    res -> denominator = N11(A -> denominator, B);

    if (sign==1)
    {
        res->numerator->sign=false;

    }

    free_natural(temp_denominator);
    free_natural(B);
    return res;
}
