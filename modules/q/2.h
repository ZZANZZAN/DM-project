#include <stdbool.h>
//Китаев Иван 9305
//Проверка на целое
bool Q2(fraction *A) {

    if (((A->denominator->length) == 1) && (A->denominator->digits[0] == 1)) { // если знаменатель равен 1 то целое
        return true;
    } else { //
        natural *B = NULL, *C = NULL;

        B = init_natural(A->numerator->length);
        for (size_t j = 0; j < (B->length); j++) B->digits[j] = (A->numerator->digits[j]);
        C = copy_natural(A->denominator);

        if (N1(B, C) == 0) { // если числитель равен знаменателю то целое
            free_natural(B);
            free_natural(C);
            return true;
        } else {
            natural *F = NULL;
            F = N13(B, C);

            if (N1(F, C) == 0) { //если НОД равен знаменателю то целое
                free_natural(B);
                free_natural(C);
                free_natural(F);
                return true;
            } else { // если не равны то не целое
                free_natural(B);
                free_natural(C);
                free_natural(F);
                return false; }
        }
    }
}
