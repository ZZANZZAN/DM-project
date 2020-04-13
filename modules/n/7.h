#include <stdint.h>		// SIZE_MAX


natural *N7(natural *A, int k)
{
	if(N2(A) == false) return A;
	
    resize_natural(A, (A -> length) + k);// увеличение размера массива, на k элементов
    
    for(size_t i = A -> length - 1; i >= (size_t)k && i != SIZE_MAX; --i)// заполнение новых ячеек массива 0
    {
        A -> digits[i] = A -> digits[i - k];
    }
    
    for(size_t i = 0; i < (size_t)k; ++i)
		A -> digits[i] = 0;
    
    return A;
}
