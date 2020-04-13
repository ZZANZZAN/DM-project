//проверка на ноль, проход по масссиву в поисках отличной от нуля цифры
bool N2(natural *x) {
    
    bool flag = false;

    for (size_t i = 0; i < (x -> length); i++)
        if (x -> digits[i] != 0)
            flag = true;
    
    return flag;
}
