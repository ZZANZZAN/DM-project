integer *Z3(integer *A)
{
    integer *res;
    res = init_integer(A -> length);
    res -> sign = A -> sign;
    for(size_t i = 0 ; i < res -> length ; i++)
        res -> digits[i] = A -> digits[i];
    //checking the number at 0
    if ((res -> digits[0] == 0)&&(res -> length == 1))
        return(res);
    //multiplying a number by (-1)
    if (res -> sign == true)
            res -> sign = false;
    else
        res -> sign = true;
    return(res);
}
