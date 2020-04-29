//Игнатьев Константин 9305
//Преобразование натурального в целое
integer *Z4(natural *A)
{
    size_t i;
    integer *B;
    B = init_integer(A -> length);
    for (i = 0 ; i < A -> length ; i++) 
        B -> digits[i] = A -> digits[i];//Копирование цифр
    B -> sign = true;
    return B;
}
