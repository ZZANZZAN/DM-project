//Чугуй Владимир 9305
//Остаток от деления целого числа на натуральное
integer *Z10(integer *A, integer *B) {
    integer *Result, *quotient, *temp_result;
    quotient = Z9(A, B);//Вычисление частного
    Result = Z8(quotient, B);//Умножение частного на делитель
    temp_result = Result;
    Result = Z7(A, temp_result);//Вычисление остатка
    free_integer(temp_result);
    free_integer(quotient);

    return (Result);
}
