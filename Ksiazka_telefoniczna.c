#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct{
  char* nazwisko;
  char* nrTelefonu;
  float nrKierunkowy;
}ksiazka_telefoniczna_t;


void wyswietl_wszystko(ksiazka_telefoniczna_t* ksiazka){

printf("Lp.    Nazwisko     Numer Telefonu    Numer kierunkowy\n");
  for(int i=0; i<MAX; i++)
      printf("%d.    %s        %s             +%.0f\n",i+1, ksiazka[i].nazwisko,
                  ksiazka[i].nrTelefonu, ksiazka[i].nrKierunkowy);
}

void wyswietl(ksiazka_telefoniczna_t* ksiazka,int indeks){
    printf("Nazwisko: %s\nNumer Telefonu: %s\nNumer kierunkowy: +%.0f\n",ksiazka[indeks].nazwisko,
                ksiazka[indeks].nrTelefonu, ksiazka[indeks].nrKierunkowy);
}


int main(){

  ksiazka_telefoniczna_t* ksiazka = malloc(sizeof(ksiazka_telefoniczna_t)*MAX);
  ksiazka[0].nazwisko = "Zięba";
  ksiazka[0].nrTelefonu = "792 456 546";
  ksiazka[0].nrKierunkowy = 48;

  ksiazka[1].nazwisko = "Proszowski";
  ksiazka[1].nrTelefonu = "505 570 144";
  ksiazka[1].nrKierunkowy = 48;

  ksiazka[2].nazwisko = "Derwisz";
  ksiazka[2].nrTelefonu = "500 058 432";
  ksiazka[2].nrKierunkowy = 48;

  ksiazka[3].nazwisko = "Jobs";
  ksiazka[3].nrTelefonu = "777 968 543";
  ksiazka[3].nrKierunkowy = 46;

  ksiazka[4].nazwisko = "Lisowska";
  ksiazka[4].nrTelefonu = "666 324 666";
  ksiazka[4].nrKierunkowy = 48;

  wyswietl_wszystko(ksiazka);
  int n;
printf("Podaj, ktora pozycje chcesz wyswietlic: ");
scanf("%d",&n);
wyswietl(ksiazka,n-1);

  return 0;
}
