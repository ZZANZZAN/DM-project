integer *Z4(natural *A)
{
size_t i;
integer *B;
B = init_integer(A -> length);
for (i = 0 ; i < A -> length ; i++) B->digits[i] = A->digits[i];
B -> sign = true;
return B;

}