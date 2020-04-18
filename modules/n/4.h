natural *N4(natural *A, natural *B) {
    
    bool was_swap = false;
    
    if((A -> length) < (B -> length))
    {
        // Перестановка чисел
        swap_natural(&A, &B);
        was_swap = true;
    }
    
    // A > B
    
    natural *C = init_natural(A -> length);
    
    signed char sum = 0;
    
    
    // Суммирование
    
    for(size_t i = 0; i < (B -> length); ++i)
    {
        sum += A -> digits[i] + B -> digits[i];
        C -> digits[i] = sum % 10;
        sum /= 10;
    }
    
    
    // Учёт переполнения
    
    for(size_t i = (B -> length); i < (A -> length); ++i)
    {
        sum += A -> digits[i];
        C -> digits[i] = sum % 10;
        sum /= 10;
    }
    
    
    if(sum != 0)
    {
        resize_natural(C, (A -> length) + 1);
        C -> digits[(A -> length)] = sum;
    }
    
    if(was_swap == true)
    {
        // Обратная перестановка
        swap_natural(&A, &B);
    }
    
    return C;
}
