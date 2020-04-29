//Бессонов Никита 9305
//Этот модуль умножает натуральные числа
natural *N8(natural *A, natural *B)
{
    natural *res;
    natural *temp;
    natural *t;
    size_t i , temp_length;
    res = init_natural(1);
    res -> digits[0] = 0;
    if (A -> length > B -> length)
    {
        temp_length = B -> length;
        for (i = 0 ; i < temp_length; i++)//Идём циклом до длины самого короткого числа
        {
            temp = N6 (A, B -> digits[i]);//Умножаем число на последнюю цифру второго числа
            t = temp;
            temp = N7 (temp , i);//Добавляем i нулей в конец числа
            free_natural(t);
            t = res;
            res = N4 (temp , res);//Суммируем полученное число с результатом
            free_natural(t);
            free_natural(temp);
        }
    }
    else
    {
        temp_length = A -> length;
        for (i = 0 ; i < temp_length ; i++)//Идём циклом до длины самого короткого числа
        {
        	temp = N6 (B , A -> digits[i]);//Умножаем число на последнюю цифру второго числа
            t = temp;
            temp = N7 (temp , i);//Добавляем i нулей в конец числа
            free_natural(t);
            t = res;
            res = N4 (temp , res);//Суммируем полученное число с результатом
            free_natural(t);
            free_natural(temp);
        }
    }
    return res;
}
