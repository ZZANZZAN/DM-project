#include <stdint.h>
natural *N7(natural *A, int k)
{
    if(N2(A) == false) return copy_natural(A);
    
    natural *res = copy_natural(A);
    
    resize_natural(res , (res -> length) + k);  // увеличение размера массива, на k элементов
    
    for(size_t i = res -> length - 1; i >= (size_t)k && i != SIZE_MAX; i--)
        res -> digits[i] = res -> digits[i - k];
    
    for(size_t i = 0; i < (size_t)k; i++)
		res -> digits[i] = 0;   // заполнение новых ячеек массива 0
    
    return res;
}
