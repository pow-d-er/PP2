#include "odcinki.h"

section_t* new_section(const double xb, const double yb, const double xe, const double ye){
  section_t* new = malloc(sizeof(section_t));
  new->bPoint = malloc(sizeof(point_t));
  new->ePoint = malloc(sizeof(point_t));

  new->bPoint->x = xb;
  new->bPoint->y = yb;
  new->ePoint->x = xe;
  new->ePoint->y = ye;

  return new;
}

void display(section_t* section){
  printf("Współrzędne punktu początkowego: (%.2f,%.2f)\n",section->bPoint->x,section->bPoint->y);
  printf("Współrzędne punktu końcowego: (%.2f,%.2f)\n",section->ePoint->x,section->ePoint->y);
}

double howLong(const section_t* section){
return sqrt(pow(section->ePoint->x-section->bPoint->x,2) + (section->ePoint->y-section->bPoint->y,2));
}

section_t* whichLonger(section_t* a, section_t* b){
    if(howLong(a) > howLong(b)) return a;
    else if(howLong(a)<howLong(b)) return b;

    printf("Odcinki sa rowne.");
    return a;
}

void save_sections(const char *path,int howMuch, const section_t* section){
  FILE *fp = fopen(path,"wb");

  fwrite(section,sizeof(section_t),howMuch,fp);

  fclose(fp);
}

section_t* load(const char* path, int howMuch){
    FILE *fp = fopen(path,"r");
    section_t* section = (section_t*)malloc(sizeof(section_t)*howMuch);


    if(fp){
      fread(section,sizeof(section_t),howMuch,fp);
    }else printf("Błąd odczytu pliku.");

  fclose(fp);


return section;
}

section_t* sort(const section_t* sectionsToSort, int howMuch){
  section_t* sortedSections = malloc(sizeof(section_t)*howMuch);
  section_t* helper =  malloc(sizeof(section_t));

  for(int i=0; i<howMuch; i++)
    sortedSections[i] = sectionsToSort[i];

  for(int i=0; i<howMuch; i++){
    for(int j=0; j<howMuch-1; j++){

      if(howLong(&sortedSections[j+1]) > howLong(&sortedSections[j])){
      *helper = sortedSections[j];
      sortedSections[j] = sortedSections[j+1];
      sortedSections[j+1] = *helper;
    }

    }
  }
  return sortedSections;
}

point_t* intersection(const section_t* s1,const section_t* s2){
  point_t* pIntersection = malloc(sizeof(point_t));
  double a1,a2,b1,b2;

  a1 = (s1->ePoint->y - s1->bPoint->y)/(s1->ePoint->x - s1->bPoint->x);
  a2 = (s2->ePoint->y - s2->bPoint->y)/(s2->ePoint->x - s2->bPoint->x);
  b1 = s1->ePoint->y - a1*s1->ePoint->x;
  b2 = s2->ePoint->y - a2*s2->ePoint->x;

  pIntersection->x = (b2 - b1)/(a1-a2);
  pIntersection->y = a1*pIntersection->x + b1;

  return pIntersection;
}
