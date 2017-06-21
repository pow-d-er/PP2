#include "dzialania.h"

int main(){

float a,b;
int choice = 0;

printf("Podaj pierwsza liczbe: ");
scanf("%f",&a);

printf("Podaj druga liczbe: ");
scanf("%f",&b);


printf("Wybierz dzialanie: \n1. Dodawanie\n2. Odejmowanie\n3. Mnożenie\n4. Dzielenie\n");
scanf("%d",&choice);
if(!(choice<5 && choice>0)) printf("Nie ma takiego dzialania!");
switch(choice){
  case 1:
  printf("Wynik dodawania: %.2f", calculate(a,b,sum));
  break;
  case 2:
  printf("Wynik odejmowania: %.2f", calculate(a,b,subtract));
  break;
  case 3:
  printf("Wynik mnożenia: %.2f", calculate(a,b,multiply));
  break;
  case 4:
  printf("Wynik dzielenia: %.2f", calculate(a,b,division));
  break;
}


  return 0;
}
