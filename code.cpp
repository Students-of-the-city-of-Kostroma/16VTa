#include <stdio.h> 
#include <iostream> 
#define _CRT_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_NONSTDC_NO_DEPRECATE 
#pragma warning(disable : 4996) 
#include <string.h> 
using namespace std; 
int prioritet(char a); 
int main() 
{ 
setlocale(LC_ALL, "Russian"); 
char a[100]; 
char vihod[100]; 
char stek[100]; 
int j = 0, m = 0, i = 0; 
int otvet; 
int len; 

scanf("%s", a); 

len = strlen(a); 

while ((i < len) && (a[i] != '0' || a[i] != '=')) 
{ 
if (a[i] >= '0' && a[i] <= '9') 
{ 
vihod[m] = a[i]; 
m++; 
} 

else if (a[i] == '+' || a[i] == '-' ) 
{ 
if (j == 0) 
{ 
stek[j] = a[i]; 
j++; 
} 
else 
{ 
if (prioritet(stek[j - 1]) < prioritet(a[i])) 
{ 
stek[j] = a[i]; 
j++; 
} 
else//если пpиоpитет меньше пеpеписываем в выходную стpоку все опеpации с большим или pавным пpиоpитетом записываем в стек поступившую опеpацию 
{ 
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

i++; 
} 

—j; 
while (j >= 0) 
{ 
vihod[m] = stek[j]; 
++m; 
—j; 
} 
vihod[m] = '\0'; 
cout « "Представление в обратной польской = " «vihod « endl; 
//printf("%s\n", vihod); 

//Проверочка на количество элементов в массиве - стеке 
//cout « "колво = " « m « endl; 


//еще одна проверочка (из char с int) 
//otvet = vihod[0] - '0'; 
//cout « "Переведенное значение (тестововое) = " « otvet« endl; 
//считалка 

for (int jv = 0; jv < m; jv++) 
{ 
if (vihod[jv] == '+') 
{ 
vihod[jv] = vihod[jv - 2] + vihod[jv - 1] - '0'; 

// cout « "Иф с + = " « vihod[jv] « endl; 
otvet = vihod[jv] ; 
} 
if (vihod[jv] == '-') 
{ 
vihod[jv] = vihod[jv - 2] - vihod[jv - 1] + '0'; 

// cout « "Иф с - = " « vihod[jv] « endl; 
otvet = vihod[jv] ; 
} 

} 

cout « "Ответ = " « otvet - '0' « endl; 





system("pause"); 

return 0; 
} 
int prioritet(char a) 
{ 
switch (a) 
{ 
case '-': 
case '+': 
return 2; 

} 
}
