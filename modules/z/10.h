integer *Z10(integer *A, integer *B) {
    integer *Result, *quotient, *temp_result;
    quotient = Z9(A, B);
    Result = Z8(quotient, B);
    temp_result = Result;
    Result = Z7(A, temp_result);
    free_integer(temp_result);
    free_integer(quotient);

    return (Result);
}
