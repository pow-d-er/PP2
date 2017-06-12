#include "studenci.h"

student_t* wypelnij(){
student_t* student = malloc(sizeof(student_t));

printf("Podaj imie studenta: ");
scanf("%s",student->imie);
printf("Podaj nazwisko studenta: ");
scanf("%s",student->nazwisko);
printf("Podaj numer albumu studenta: ");
scanf("%s",student->album);

return student;
}

void zwolnij_pamiec(student_t *student){
  free(student);
}

void wyswietl_pamiec(student_t *student){
printf("%ld\n",sizeof(student));
}
