integer *Z9(integer *A, integer *B) {
    integer *Result;
    natural *temp_A, *temp_B, *temp_result, *temp_temp_result, *temp;
    int znakResult;
    int znakA = Z2(A);
    int znakB = Z2(B);
    if (znakA == 0 || znakB == 0) {
        Result = init_integer(1);
        Result->digits[0] = 0;
        Result->sign = 1;
    } else {
        znakResult = 2;
        if ((znakA + znakB) == 3) znakResult = 1;
        temp_A = Z1(A);
        temp_B = Z1(B);
        temp_result = N11(temp_A, temp_B);
        temp = N12(temp_A, temp_B);

        if (znakResult == 1) {
            if (znakA == 1) {
                if ((B->length == 1 && B->digits[B->length - 1] == 1) || N2(temp) == false) {
                    Result = Z4(temp_result);
                    Result = Z3(Result);
                } else {
                    temp_temp_result = temp_result;
                    temp_result = N3(temp_temp_result);
                    free_natural(temp_temp_result);
                }
            }
            Result = Z4(temp_result);
            Result = Z3(Result);

        } else
            Result = Z4(temp_result);

        free_natural(temp_result);
        free_natural(temp_A);
        free_natural(temp_B);
        free_natural(temp);

    }


    return (Result);
}
