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
				else//���� �p��p���� ������ ��p��������� � �������� ��p��� ��� ���p���� � ������� ��� p����� �p��p������ ���������� � ���� ����������� ���p����
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
	//cout << "������������� � �������� �������� = " << vihod << endl;

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




		else if (vihod[d] == '.')			//���� �����
		{
			//cout << "d ==" << d << endl;	//�������� ��� d
			//int sc = d;
			//d++;
			//�� ���� �����, �������� ����� ��� �� ��������� �������� 
			for (d; vihod[d + 1] != 'e' && vihod[d + 1] != razdelznak; d++)
			{
				//������������� �� ���� �������, ��� ������ ����� � ��� ����� ���� ������� � ����� �� ���� ������� � ������ ����������
				//	cout << "d ==" << d << endl;  // ��� ���� ����������
				znzpt = znzpt * 10;           //���������� znzpt = 0; �������� ����� �� 10, ����� � ����������� ����� ������ �������� �������� ���� �����
				znzpt = (znzpt + vihod[d + 1] - '0'); // ����������� ����������� ����� ����� ������� ���������� � ����������� ����� ������ �������� ��������
													  //��������� �����, � ��������������� ��� �������� ����� � int
				delitel = delitel * 10;			// ������������� ��������
												//	cout << "����� ����� �������" << znzpt << endl;
												//cout << "��������" << delitel << endl;
			}

			promzn = promzn *delitel + znzpt;  //� ������ ����� �� �������, ���������� ��� ����� ����� ������� (��������, ���� ����� 12.32 
											   //�� ���������� �������� promzn = 12  znzpt = 32;
											   // �������� �� ������� promzn = 1232
			promzn = promzn / delitel;		    // ������ � ������ ��� ����� �������.
												//	cout << "������� ����������� ����� ��� ������ � ������ = " << promzn << endl;
		}


		//�������� � � ��� for (sc = sc + 1; vihod[sc] != razdelznak; sc++) 
		//��� �������������� ������� ������������, ����� ������, �� ��� �� ����� 
		/*else if (vihod[d] == 'e') //
		{
		int sc = d;						//�� ���� �����, �������� ����� ��� �� ��������� ��������

		for (sc = sc + 1; vihod[sc] != razdelznak; sc++)
		{
		d++;
		if (vihod[sc] == '+')
		{
		stepenposleE = vihod[sc + 1] - '0';
		cout << "������� ����� �+  = " <<stepenposleE << endl;
		//3e+4_;
		posleE = pow(10, stepenposleE);
		cout << "����� ����������� � ������� �����  �+ = " << posleE << endl;
		promzn = promzn*posleE;
		cout << "����� � �������� �+ ��� ������ � ������ = " << promzn << endl;
		sc++;
		d++;


		}
		else if (vihod[sc] == '-')
		{
		stepenposleE = vihod[sc + 1] - '0';
		cout << "������� ����� �-  = " << stepenposleE << endl;
		//3e+4_;
		posleE = 1 / pow(10, stepenposleE);
		cout << "����� ����������� � ������� �����  �- = " << posleE << endl;
		cout << "����� � ������� �� ���������� � �- = " << promzn << endl;
		promzn = promzn*posleE;
		cout << "����� � �������� �- ��� ������ � ������ = " << promzn << endl;
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
					//	cout << "������� ����� �+  = " << stepenposleE << endl;
					posleE = pow(10, stepenposleE);
					//cout << "����� ����������� � ������� �����  �+ = " << posleE << endl;
					promzn = promzn*posleE;
					//	cout << "����� � �������� �+ ��� ������ � ������ = " << promzn << endl;
					sc++;
					d++;
				}
				else if (vihod[d + 1] == '-')
				{
					stepenposleE = vihod[d + 2] - '0';
					//cout << "������� ����� �-  = " << stepenposleE << endl;
					posleE = 1 / pow(10, stepenposleE);
					//cout << "����� ����������� � ������� �����  �- = " << posleE << endl;
					//cout << "����� � ������� �� ���������� � �- = " << promzn << endl;
					promzn = promzn*posleE;
					//cout << "����� � �������� �- ��� ������ � ������ = " << promzn << endl;
					sc++;
					d++;

				}
			}
		}
		//������� 1.0 ��������� ��� ���������� ������ ������
		else if (vihod[d] == razdelznak && (vihod[d + 1] == '+' || vihod[d + 1] == '-' || vihod[d + 1] == '/' || vihod[d + 1] == '*') && (vihod[d - 1] == '+' || vihod[d - 1] == '-' || vihod[d - 1] == '/' || vihod[d - 1] == '*'))
		{
			//cout << "Promzn ����� ��������� 1.0 ����� ������� ============== " << promzn << endl;

		}

		else if (vihod[d] == razdelznak)
		{
			//cout <<"Promzn ����� ��������� ============== " <<promzn << endl;
			massint[k] = promzn;
			k++;
			promzn = 0;  //��������� �������� � ��������������(���� ���� ����� ����������)
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
	//cout << "���� ���������� k = " << massint[k] << endl;
	//cout << "���� ���������� k-1 = " << massint[k-1] << endl;
	//cout << "���� ���������� k-2 = " << massint[k-2] << endl;
	//cout << "���� ���������� k-3 = " << massint[k - 3] << endl;

	for (int kk = 0; kk < k; kk++)
	{
		cout << "���� ���������� (�����) = " << massint[kk] << endl;
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