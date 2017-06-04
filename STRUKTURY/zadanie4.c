#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
  double rzeczywista;
  double urojona;
}zesp_t;

zesp_t* lz(double rzeczywista, double urojona);
void ustaw(zesp_t* liczba, double rzeczywista, double urojona);
void wyswietl(zesp_t* liczba);
void dodaj(zesp_t* a, zesp_t* b, zesp_t* wynik);
void odejmij(zesp_t* a, zesp_t* b, zesp_t* wynik);
void pomnoz(zesp_t* a, zesp_t* b, zesp_t* wynik);
double modul(zesp_t* liczba);
double argument(zesp_t* liczba);

int main(){

zesp_t* wynik = malloc(sizeof(zesp_t));
zesp_t* liczba_zespolona1 = lz(5,6);
zesp_t* liczba_zespolona2 = lz(5,6);
ustaw(liczba_zespolona1,3,2);
wyswietl(liczba_zespolona1);
wyswietl(liczba_zespolona2);
dodaj(liczba_zespolona1, liczba_zespolona2,wynik);
printf("Wynik dodawania: "); wyswietl(wynik);
odejmij(liczba_zespolona1, liczba_zespolona2,wynik);
printf("Wynik odejmowania: "); wyswietl(wynik);
pomnoz(liczba_zespolona1, liczba_zespolona2,wynik);
printf("Wynik mnożenia: "); wyswietl(wynik);


printf("Moduł liczby (%.2f,%.2f): %.2f\n",
            liczba_zespolona1->rzeczywista,liczba_zespolona1->urojona,
            modul(liczba_zespolona1));


printf("Argument liczby (%.2f,%.2f): %.2f\n",
            liczba_zespolona1->rzeczywista,liczba_zespolona1->urojona,
            argument(liczba_zespolona1));

  return 0;
}

zesp_t* lz(double rzeczywista, double urojona){
  zesp_t *lz = malloc(sizeof(zesp_t));

  lz->rzeczywista = rzeczywista;
  lz->urojona = urojona;

  return lz;
}

void ustaw(zesp_t* liczba, double rzeczywista, double urojona){

  if(liczba == NULL){
    printf("Podany wskaznik na strukture ma wartosc NULL!");

  }else{

    liczba->rzeczywista = rzeczywista;
    liczba ->urojona = urojona;
  }
}

void wyswietl(zesp_t* liczba){

  if(liczba == NULL){
    printf("Podany wskaznik na strukture ma wartosc NULL!");
  }else{

  printf("(%.2f, %.2f)\n",
                liczba->rzeczywista, liczba->urojona);
    }
}
void dodaj(zesp_t* a, zesp_t* b, zesp_t* wynik){

  if(a == NULL || b==NULL){
    printf("Podany wskaznik na strukture ma wartosc NULL!");

  }else{
  wynik->rzeczywista = a->rzeczywista + b->rzeczywista;
  wynik->urojona = a->urojona + b->urojona;
}
}

void odejmij(zesp_t* a, zesp_t* b, zesp_t* wynik){
    if(a == NULL || b==NULL){
      printf("Podany wskaznik na strukture ma wartosc NULL!");

    }else{
    wynik->rzeczywista = a->rzeczywista - b->rzeczywista;
    wynik->urojona = a->urojona - b->urojona;
  }
}

void pomnoz(zesp_t* a, zesp_t* b, zesp_t* wynik){

  if(a == NULL || b==NULL){
    printf("Podany wskaznik na strukture ma wartosc NULL!");

  }else{
    wynik->rzeczywista = a->rzeczywista*b->rzeczywista -
                  a->urojona*b->urojona;

    wynik->urojona = a->rzeczywista*b->urojona +
                a->urojona*b->rzeczywista;
      }
}

double modul(zesp_t* liczba){
    if(liczba == NULL){
      printf("Podany wskaznik na strukture ma wartosc NULL!");

    }else
    return sqrt(pow(liczba->rzeczywista,2)+pow(liczba->urojona,2));
}

double argument(zesp_t* liczba){

if(liczba == NULL){
  printf("Podany wskaznik na strukture ma wartosc NULL!");

}else{

if(liczba->rzeczywista == 0){
  if(liczba->urojona > 0){ return M_PI/2;
  }else return -M_PI/2;
} else if(liczba->rzeczywista > 0){
   return atan(liczba->urojona/liczba->rzeczywista);
 }else return atan(liczba->rzeczywista/liczba->urojona) + M_PI;
 printf("Argument jest nieokreślony");
 }
}
