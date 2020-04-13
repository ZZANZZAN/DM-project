
integer *Z3(integer *A)
{
    //checking the number at 0
    if (A -> digits[0] == 0)
        return(A);
    //multiplying a number by (-1)
    if (A -> sign == true)
            A -> sign = false;
    else 
        A -> sign = true;
    return(A);
}
