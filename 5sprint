#include <stdio.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#pragma warning(disable : 4996)
#include <string.h>
using namespace std;
int prioritet(char a);


int otvet(char a[])
{
	char razdelznak = '_';
	char vihod[100];
	char stek[100];
	int j = 0, m = 0, i = 0;
	int otvet;
	char perem;
	int len;


	len = strlen(a);

	while ((i < len) && (a[i] != '0' || a[i] != '='))
	{
		if (a[i] >= '0' && a[i] <= '9' || a[i] == '.')
		{
			vihod[m] = a[i];
			m++;
		}
		else if (a[i] == '(')
		{
			stek[j] = a[i];
			j++;
		}

		
		else if (a[i] == 'e')
		{
			vihod[m] = a[i];
			vihod[m + 1] = a[i + 1];
			vihod[m + 2] = a[i + 2];
			m = m + 3;
			i = i + 2;
		}
		

		else if (a[i] == '+' || a[i] == '-' || a[i] == '/' || a[i] == '*')
		{
			if (j == 0)
			{
				vihod[m] = razdelznak;
				m++;
				stek[j] = a[i];
				j++;
			}
			else
			{
				if (prioritet(stek[j - 1]) < prioritet(a[i]))
				{
					vihod[m] = razdelznak;
					m++;
					stek[j] = a[i];
					j++;
				}
				else//если пpиоpитет меньше пеpеписываем в выходную стpоку все опеpации с большим или pавным пpиоpитетом записываем в стек поступившую опеpацию
				{
					vihod[m] = razdelznak;
					m++;
					while (j >= 1 && prioritet(stek[j - 1]) >= prioritet(a[i]))
					{
						vihod[m] = stek[j - 1];
						m++;
						j--;
					}
					stek[j] = a[i];
					++j;
				}
			}
		}
		if (a[i] == ')')
		{
			while (stek[j - 1] != '(')
			{
				vihod[m] = razdelznak;
				m++;
				
				vihod[m] = stek[j - 1];

				j--;
				m++;

			}
			j--;
		}

		i++;
	}



	--j;
	vihod[m] = razdelznak;
	m++;
	while (j >= 0)
	{
		vihod[m] = stek[j];
		++m;
		--j;
	}
	vihod[m] = '\0';
	//cout << "Представление в обратной польской = " << vihod << endl;

	float massint[100];
	int k = 0;
	float promzn = 0;
	float maspromzn;
	int delitel = 1;
	int sc;
	int znzpt = 0;
	float posleE;
	int stepenposleE;


	for (int d = 0; d <= m; d++)
	{

		if (vihod[d] >= '0' && vihod[d] <= '9')
		{
			promzn = promzn * 10 + (vihod[d] - '0');
		}




		else if (vihod[d] == '.')			//если точка
		{
			//cout << "d ==" << d << endl;	//проверка для d
			//int sc = d;
			//d++;
			//не знаю зачем, возможно можно как то упростить алгоритм 
			for (d; vihod[d + 1] != 'e' && vihod[d + 1] != razdelznak; d++)
			{
				//перескакиваем на след элемент, при первом входе в ФОР нужно чтоб перейти с точки на след элемент и начать вычисление
				//	cout << "d ==" << d << endl;  // еще одна проверочка
				znzpt = znzpt * 10;           //изначально znzpt = 0; умножает число на 10, чтобы в появившийся новый разряд десятков записать след число
				znzpt = (znzpt + vihod[d + 1] - '0'); // продолжение составления числа после зарятой записываем в появившийся новый разряд десятков считаное
				//следующее число, и преобразовываем это считаное число в int
				delitel = delitel * 10;			// высчитывается делитель
			//	cout << "Числа после запятой" << znzpt << endl;
				//cout << "Делитель" << delitel << endl;
			}

			promzn = promzn *delitel + znzpt;  //к нашему числу до запятой, прибавляет все знаки после запятой (например, было число 12.32 
			//до выполнения действия promzn = 12  znzpt = 32;
			// действия мы получим promzn = 1232
			promzn = promzn / delitel;		    // ставит в нужное нам место запятую.
		//	cout << "Готовое разделенное число для записи в массив = " << promzn << endl;
		}


		//действия с Е при for (sc = sc + 1; vihod[sc] != razdelznak; sc++) 
		//При непредвиденных ошибках раскоментить, может помочь, но это не тончо 
		/*else if (vihod[d] == 'e') //
		{
		int sc = d;						//не знаю зачем, возможно можно как то упростить алгоритм

		for (sc = sc + 1; vihod[sc] != razdelznak; sc++)
		{
		d++;
		if (vihod[sc] == '+')
		{
		stepenposleE = vihod[sc + 1] - '0';
		cout << "Степень после Е+  = " <<stepenposleE << endl;
		//3e+4_;
		posleE = pow(10, stepenposleE);
		cout << "Число возведенное в степень после  Е+ = " << posleE << endl;
		promzn = promzn*posleE;
		cout << "Число с расчетом Е+ для записи в массив = " << promzn << endl;
		sc++;
		d++;


		}
		else if (vihod[sc] == '-')
		{
		stepenposleE = vihod[sc + 1] - '0';
		cout << "Степень после Е-  = " << stepenposleE << endl;
		//3e+4_;
		posleE = 1 / pow(10, stepenposleE);
		cout << "Число возведенное в степень после  Е- = " << posleE << endl;
		cout << "Число в массиве до возведения в Е- = " << promzn << endl;
		promzn = promzn*posleE;
		cout << "Число с расчетом Е- для записи в массив = " << promzn << endl;
		sc++;
		d++;

		}
		}
		}*/

		else if (vihod[d] == 'e') // 
		{
			for (d; vihod[d + 1] != razdelznak; d++)
			{
				if (vihod[d + 1] == '+')
				{
					stepenposleE = vihod[d + 2] - '0';
				//	cout << "Степень после Е+  = " << stepenposleE << endl;
					posleE = pow(10, stepenposleE);
//cout << "Число возведенное в степень после  Е+ = " << posleE << endl;
					promzn = promzn*posleE;
				//	cout << "Число с расчетом Е+ для записи в массив = " << promzn << endl;
					sc++;
					d++;
				}
				else if (vihod[d + 1] == '-')
				{
					stepenposleE = vihod[d + 2] - '0';
					//cout << "Степень после Е-  = " << stepenposleE << endl;
					posleE = 1 / pow(10, stepenposleE);
					//cout << "Число возведенное в степень после  Е- = " << posleE << endl;
					//cout << "Число в массиве до возведения в Е- = " << promzn << endl;
					promzn = promzn*posleE;
					//cout << "Число с расчетом Е- для записи в массив = " << promzn << endl;
					sc++;
					d++;

				}
			}
		}
		//Вариант 1.0 дописываю для правильной работы скобок
		else if (vihod[d] == razdelznak && (vihod[d + 1] == '+' || vihod[d + 1] == '-' || vihod[d + 1] == '/' || vihod[d + 1] == '*') && (vihod[d - 1] == '+' || vihod[d - 1] == '-' || vihod[d - 1] == '/' || vihod[d - 1] == '*'))
		{
			//cout << "Promzn чисто проверить 1.0 новое условие ============== " << promzn << endl;
		
		}
	
		else if (vihod[d] == razdelznak)
		{
			//cout <<"Promzn чисто проверить ============== " <<promzn << endl;
			massint[k] = promzn;
			k++;
			promzn = 0;  //скидываем значения к первоначальным(ниже тоже самое происходит)
			znzpt = 0;
			posleE = 0;
			delitel = 1;
		}
		else if (vihod[d] == '+')
		{
			massint[k - 2] = massint[k - 2] + massint[k - 1];
			k--;
		}
		else if (vihod[d] == '-')
		{
			massint[k - 2] = massint[k - 2] - massint[k - 1];
			k--;
		}
		else if (vihod[d] == '*')
		{
			massint[k - 2] = massint[k - 2] * massint[k - 1];
			k--;
		}
		else if (vihod[d] == '/')
		{
			massint[k - 2] = massint[k - 2] / massint[k - 1];
			k--;
		}
	}
		//cout << "Тест ИнтМассива k = " << massint[k] << endl;
		//cout << "Тест ИнтМассива k-1 = " << massint[k-1] << endl;
		//cout << "Тест ИнтМассива k-2 = " << massint[k-2] << endl;
		//cout << "Тест ИнтМассива k-3 = " << massint[k - 3] << endl;

	for (int kk = 0; kk < k; kk++)
	{
	cout << "Тест ИнтМассива (Ответ) = " << massint[kk] << endl;
	}

}
int prioritet(char a)
{
	switch (a)
	{
	case '*':
	case '/':
		return 3;
	case '-':
	case '+':
		return 2;
	case '(':
		return 1;
	

	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	char a[100];
	scanf("%s", a);

	otvet(a);

	system("pause");

	return 0;
}
