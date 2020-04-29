//Игнатьев Константин 9305
//Умножение целого числа на -1
integer *Z3(integer *A)
{
    integer *res;

    res = copy_integer(A);

    if ((res->digits[0] == 0)&&(res -> length == 1))//Проверка на ноль
        res->sign=true;
    else
    {
        if (res->sign)//Изменение знака
            res->sign=false;
        else
            res->sign=true;
    }

    return res;
}
