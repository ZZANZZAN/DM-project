natural *N11(natural *A, natural *B) {

    natural *dividend = NULL, *divider = NULL;
    natural *result = NULL, *temp = NULL, *temp_new = NULL, *temp_dividend = NULL;

    int n = 1;
   
    if (N1(A, B) == 2) {
        dividend = copy_natural(A);       
        divider = copy_natural(B);       

    } else {
        dividend = copy_natural(B);
        divider = copy_natural(A);
    }

    while (N1(divider, dividend) != 2) { //пока делитемое больше делителя
        temp = N10(dividend, divider); // поразрядно находим частное    
        if (n == 1) {
            result = copy_natural(temp);                                  
        } else
            result = N4(temp, result);// складываем разряды частного

        temp_new = N8(divider, temp); // находим произведение частного и делителя 
        free_natural(temp);
        temp_dividend = N5(dividend,
                           temp_new); // вычитаем из делимого произведение   
        free_natural(dividend);
        dividend = temp_dividend;
        n++;
        free_natural(temp_new);
    }                                                  

    free_natural(dividend);
    free_natural(divider);

    return (result);


}

