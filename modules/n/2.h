//проверка на ноль, проход по масссиву в поисках отличной от нуля цифры
bool n2(natural x){
bool flag=0;

for (int i=0;i<x->length;i++)
    if (x->digits[i]!=0)
        flag=1;
        
return flag;
}
