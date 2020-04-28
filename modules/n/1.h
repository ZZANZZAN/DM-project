#include <stdint.h>
// Боголюбова Вера 9305
//Данный модуль сравнивает два натуральных числа
int N1(natural *A, natural *B)
{
    //Сравнение длин чисел
    if((A -> length) > (B -> length))
    {
        return 2;
    }
    else if((A -> length) < (B -> length))
    {
        return 1;
    }
    else
    {
        //Если числа одинаковой длины, то сравниваем их по цифрам
        for(size_t i = (A -> length) - 1; i != SIZE_MAX; --i)//В size_t когда счётчик доходит до 0 и уменьшается на единицу, то он становится равен константе SIZE_MAX, определенной в stdint
        {
            if(A -> digits[i] > (B -> digits[i]))
                return 2;
            else if((A -> digits[i]) < (B -> digits[i]))
                return 1;
        }
        
        return 0;
    }
}
