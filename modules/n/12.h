//Китаев Иван 9305
//Вычисление остатка от деления
natural *N12(natural *A, natural *B) 
{
    natural *remainder = NULL, *quotient = NULL, *divider = NULL, *dividend = NULL, *temp = NULL;

    quotient = N11(A, B); // частное от деления A на B
    divider = copy_natural(B);
    dividend = copy_natural(A);

    temp = N8(divider, quotient); // частное умножаем на делитель
    remainder = N5(dividend, temp); // вычитаем из делимого произведение

    free_natural(dividend);
    free_natural(divider);
    free_natural(temp);
    free_natural(quotient);

    return remainder;
}
