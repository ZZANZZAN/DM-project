integer *Z3(integer *A)
{
    integer *res;

    res = copy_integer(A);

    if ((res->digits[0] == 0)&&(res -> length == 1))
        res->sign=true;
    else
    {
        if (res->sign)
            res->sign=false;
        else
            res->sign=true;
    }

    return res;
}
