#include "studenci.h"

int main(){

student_t *student1 = wypelnij();


printf("Imie: %s\nNazwisko: %s\nNr albumu: %s\n",student1->imie,student1->nazwisko,student1->album);
wyswietl_pamiec(student1);
zwolnij_pamiec(student1);
wyswietl_pamiec(student1);

  return 0;
}
