polynomial *P2(polynomial *A, polynomial *B)// модуль вычитания двух многочленов
{
  int i = 0;//переменная для прохождению по массиву
  
  if(A -> degree > B -> degree){//определяем степень какого многочлена больше
    polynomial *С = copy_polynomial(A);
    for(i = 0; i < B -> degree+1; i++){
      C -> factors[i] = Q6(A -> factors[i], B -> factors[i]);//вызов функции вычитания рациональных дробей
    }
  }
  else{//все действия происходят аналогично но многочлены меняются местами 
    polynomial *С = copy_polynomial(B);
    for(i = 0; i < A -> degree+1; i++){
      C -> factors[i] = Q6(B -> factors[i], A -> factors[i]);//вызов функции вычитания рациональных дробей
    }
  }
  return C;
}
