natural *N4(natural *A, natural *B){

    size_t i = 0;

    if (N1(A,B)==2)
    {    //A>B
        for(i=0;i < B->length;i++)
        {
            A->digits[i]=(A->digits[i])+(B->digits[i]);
            if(A->digits[i]>9){
                A->digits[i]=A->digits[i]-10;
                if(i == (A->length-1)) {
                    resize_natural(A, (A -> length) + 1);
                    A -> digits[A -> length - 1] = 1;
                } else ++(A -> digits[i+1]);

            }
        }
        return A;
    } else {    //A<B or A=B
        for(i=0;i < A->length;i++){
            B->digits[i]=(B->digits[i])+(A->digits[i]);
            if(B->digits[i]>9){
                B->digits[i]=B->digits[i]-10;
                if(i == (B->length-1)) {
                    resize_natural(B, (B -> length) + 1);
                    B -> digits[B -> length - 1] = 1;
                } else ++(B -> digits[i+1]);

            }
        }
        return B;
    }

}
