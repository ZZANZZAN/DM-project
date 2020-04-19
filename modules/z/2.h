
int Z2(integer *A){

    //checking the number at 0

    if ((A->digits[0]==0)&&(A -> length == 1))
        return(0);

    //checking the number by sign
    if (A->sign==true)

        return (2);

    else return (1);
}
