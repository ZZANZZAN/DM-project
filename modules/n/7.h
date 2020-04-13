#include <stdint.h>
natural *N7(natural *A, int k)
{
    if(N2(A) == false)
        return A;
    size_t i;
    natural *res;
    res = init_natural(A -> length);
    for(i = 0 ; i < res -> length ; i++)
        res -> digits[i]  = A -> digits[i];
    resize_natural(res , (res -> length) + k);// увеличение размера массива, на k элементов
    for(i = res -> length - 1; i >= (size_t)k && i != SIZE_MAX; i--)// заполнение новых ячеек массива 0
    {
        res -> digits[i] = res -> digits[i - k];
    }
    for(i = 0; i < (size_t)k; i++)
		res -> digits[i] = 0;

    return res;
}
