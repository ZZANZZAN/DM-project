//проверка на ноль, проход по масссиву в поисках отличной от нуля цифры
bool N2(natural *N) 
{
    if((N -> length) == 1 && N -> digits[0] == 0)
        return false;
    else return true;
}
