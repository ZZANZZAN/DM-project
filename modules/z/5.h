//Когутенко Андрей 9305
//Преобразование целого неотрицательного в натуральное
natural *Z5(integer *A)
{
    size_t i;
    natural *B;
    B = init_natural(A -> length);
    for(i = 0 ; i < B-> length ; i++) 
        B -> digits[i] = A -> digits[i];//Копирование цифр
    return B;
}
