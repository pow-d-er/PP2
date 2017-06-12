#include "liczby_zespolone.h"

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
