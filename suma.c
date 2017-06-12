#include <stdio.h>

typedef double( * dzialanie )( double, double );

double SUMA(double a, double b){
  return a+b;
}

double ODEJMOWANIE(double a, double b){
  return a-b;
}

double oblicz(double a, double b, dzialanie dz){
  return dz(a,b);
}


int main(){

double a,b;
printf("Podaj pierwsza liczbe: \n");
scanf("%lf",&a);
printf("Podaj pierwsza liczbe: \n");
scanf("%lf",&b);

printf("Wynik dodawania to: %.2f\n",oblicz(a,b,SUMA));
printf("Wynik odejmowania to: %.2f\n",oblicz(a,b,ODEJMOWANIE));

  return 0;
}
