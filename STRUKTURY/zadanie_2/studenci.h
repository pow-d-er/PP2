#ifndef studenci_h
#define studenci_h

#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char imie[100];
  char nazwisko[100];
  char album[10];
}student_t;

student_t* wypelnij();
void zwolnij_pamiec(student_t *student);
void wyswietl_pamiec(student_t *student);



#endif
