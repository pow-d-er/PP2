#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char imie[100];
  char nazwisko[100];
  char album[10];
}student_t;

student_t* wypelnij(){
student_t* student;

printf("Podaj imie studenta: ");
scanf("%s",student->imie);
printf("Podaj nazwisko studenta: ");
scanf("%s",student->nazwisko);
printf("Podaj numer albumu studenta: ");
scanf("%s",student->album);

return student;
}

int main(){

student_t *student1 = wypelnij();

  return 0;
}
