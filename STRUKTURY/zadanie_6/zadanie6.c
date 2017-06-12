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
return sqrt(pow(section->ePoint->x-section->bPoint->x,2) + pow(section->ePoint->y-section->bPoint->y,2));
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
    section_t* section = malloc(sizeof(section_t)*howMuch);


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

void designate_coefficients(const section_t* s,double *a, double *b){
    *a = (s->ePoint->y - s->bPoint->y)/(s->ePoint->x - s->bPoint->x);
    *b = s->ePoint->y - *a*s->ePoint->x;

}

int designate_beginning(const section_t* section){
  int beginning;
  if(section->ePoint->x<section->bPoint->x ) beginning = section->ePoint->x ;
  else beginning = section->bPoint->x;

  return beginning;
}

point_t* intersection(const section_t* s1,const section_t* s2){
  point_t* pIntersection = malloc(sizeof(point_t));
  double a1,a2,b1,b2;

  designate_coefficients(s1,&a1,&b1);
  designate_coefficients(s2,&a2,&b2);

  pIntersection->x = (b2 - b1)/(a1-a2);
  pIntersection->y = a1*pIntersection->x + b1;

  return pIntersection;
}

point_t* designate_points(const section_t* section){

    double a,b;

    point_t* points = malloc(sizeof(point_t)*(abs(section->ePoint->x - section->bPoint->x)+1));
    designate_coefficients(section,&a,&b);
    int beginning = designate_beginning(section);
    for(int i = 0;  i<abs(section->ePoint->x - section->bPoint->x)+1; i++){
      points[i].x =beginning;
      points[i].y = a*points[i].x +b;
      beginning++;
    }

    return points;

}
