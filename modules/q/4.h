//Boykova V.A.
integer *Q4( fraction *A) {
        integer *R;
        //test for the ability to transform into integer
        if ((( A -> denominator -> length ) == 1) && (( A -> denominator -> digits[0] ) == 1)){
            R = copy_integer(A -> numerator);
        }
        else{
            R = init_integer(0);
        }
    return R;
}
