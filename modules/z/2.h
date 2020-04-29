//Есин Артём 9305
//Определение положительности числа
int Z2(integer *A)
{
    //Проверка на ноль
    if ((A -> digits[0] == 0) && (A -> length == 1))
        return(0);

    //Проверка знака числа
    if (A -> sign == true)
        return (2);

    else return (1);
}
