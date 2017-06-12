#ifndef odcinki_h
#define odcinki_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct{
  double x;
  double y;
}point_t;

typedef struct{
point_t* bPoint;
point_t* ePoint;
}section_t;

section_t* new_section(const double xb, const double yb, const double xe, const double ye);
void display(section_t* section);
double howLong(const section_t* section);
section_t* whichLonger(section_t* a, section_t* b);
void save_sections(const char *path,int howMuch, const section_t* section);
section_t* load(const char* path, int howMuch);
section_t* sort(const section_t* sectionsToSort, int howMuch);
point_t* intersection(const section_t* s1,const section_t* s2);


#endif
