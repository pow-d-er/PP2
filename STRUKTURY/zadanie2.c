#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char imie[100];
  char nazwisko[100];
  char album[10];
}student_t;

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

int main(){

student_t *student1 = wypelnij();


printf("Imie: %s\nNazwisko: %s\nNr albumu: %s\n",student1->imie,student1->nazwisko,student1->album);
wyswietl_pamiec(student1);
zwolnij_pamiec(student1);
wyswietl_pamiec(student1);

  return 0;
}