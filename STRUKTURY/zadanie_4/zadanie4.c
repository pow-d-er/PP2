#include "liczby_zespolone.h"

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
