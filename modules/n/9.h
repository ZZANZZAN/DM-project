//Кацер Евгений 9307
//Этот модуль находит разность между первым числом и вторым, умноженным на цифру
natural *N9(natural *A, natural *B, int c)
{
    natural *C = NULL, *res = NULL;
    C = N6 (B , c);//Умножаем число на цифру
    res = N5 (A , C);//Находим их разность
    free_natural(C);
    return res;
}
