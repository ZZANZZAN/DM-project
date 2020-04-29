//Ковалёва Ксения 9305
//Нахождение НОД двух чисел
natural *N13(natural *A,natural *B)
{
    natural *first = NULL, *second = NULL, *temp = NULL;
    first = copy_natural(A);
    second = copy_natural(B);
    while(N2(first) && N2(second))//Ниже реализован алгоритм Евклида через остатки от деления
    {
        if(N1(first , second)==2)
        {
            temp = N12(first , second);//Вычисление остатка от деления
            free_natural(first);
            first = NULL;
            first = temp;
        }
        else
        {
            temp = N12(second , first);//Вычисление остатка от деления
            free_natural(second);
            second = NULL;
            second = temp;
        }
    }
    if(N2(first))//Проверка на ноль
    {
        free_natural(second);
        return first;
    }
    else
    {
        free_natural(first);
        return second;
    }
}
