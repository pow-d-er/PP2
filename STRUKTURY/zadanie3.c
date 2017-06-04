#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char *imie;
  char *nazwisko;
  char *album;
}student_t;

student_t* wypelnij(){
student_t* student = malloc(sizeof(student_t));
student->imie = malloc(sizeof(char)*100);
student->nazwisko = malloc(sizeof(char)*100);
student->album = malloc(sizeof(char)*10);



printf("Podaj imie studenta: ");
scanf("%s",student->imie);
printf("Podaj nazwisko studenta: ");
scanf("%s",student->nazwisko);
printf("Podaj numer albumu studenta: ");
scanf("%s",student->album);

return student;
}

void zwolnij_pamiec(student_t *student){
  free(student->imie);
  free(student->nazwisko);
  free(student->album);
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
