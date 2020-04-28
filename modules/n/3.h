//Бойкова Валерия 9305
//Данный модуль добавляет к числу единицу
natural *N3(natural *A)
{
	natural *res;
	res = copy_natural(A);
	size_t i = 0;
	while(i < (res -> length) && (res -> digits[i]) == 9)//Идём циклом с начала числа и заменяем 9 на 0
		res -> digits[i++] = 0;
	//Условие при переполнении числа
	if(i == (res -> length))
	{
		resize_natural(res, (res -> length) + 1);
		res -> digits[(res -> length) - 1] = 1;
	}
	else
        ++(res -> digits[i]);//Прибавление к цифре единицу
	return res;
}
