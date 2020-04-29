//Кацер Евгений 9307
//Данный модуль вычисляет первую цифру деления двух чисел
signed char N10(natural *A, natural *B) {
    natural *C = NULL, *D = NULL, *N = NULL, *temp1 = NULL, *temp2 = NULL;
    signed char t = 0;
    size_t q;
    C = copy_natural(A);
    D = copy_natural(B);
    N = copy_natural(B);

    q = N1(A, B);//Сравнение двух чисел
    if(q == 2)
    {
        free_natural(D);
        D = N7(B, 1);//Умножение числа на 10
        while((N1(C, D) == 2) || (N1(C, D) == 0))//Умножение N на 10, пока D меньше C
        {
            temp1 = N7(D, 1);
            free_natural(D);
            D = NULL;
            D = temp1;
          

            temp2 = N7(N, 1);
            free_natural(N);
            N = NULL;
            N = temp2;
            
        }
        while((N1(C, N) == 2) || (N1(C, N) == 0))
        {
            temp1 = N5(C, N);//Вычитаем из C N пока C >= N
            free_natural(C);
            C = temp1;
            t++;//Увеличение счётчика
        }
    }
    else
        if(q == 1)
            t = 0;
        else
            if(q == 0)
                t = 1;
    free_natural(C);
    free_natural(D);
    free_natural(N);
    return t;
}
