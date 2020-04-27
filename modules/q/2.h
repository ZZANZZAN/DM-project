#include <stdbool.h>

bool Q2(fraction *A) {

    if (((A->denominator->length) == 1) && (A->denominator->digits[0] == 1)) {
        return true;
    } else {
        natural *B = NULL, *C = NULL;

        B = init_natural(A->numerator->length);
        for (size_t j = 0; j < (B->length); j++) B->digits[j] = (A->numerator->digits[j]);
        C = copy_natural(A->denominator);

        if (N1(B, C) == 0) {
            free_natural(B);
            free_natural(C);
            return true;
        } else {
            natural *F = NULL;
            F = N13(B, C);

            if (N1(F, C) == 0) {
                free_natural(B);
                free_natural(C);
                free_natural(F);
                return true;
            } else {
                free_natural(B);
                free_natural(C);
                free_natural(F);
                return false; }
        }
    }
}
