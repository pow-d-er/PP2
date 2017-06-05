#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct{
double xb;
double yb;
double xe;
double ye;
}section_t;

typedef struct{
  double x;
  double y;
}point_t;

section_t* new_section(const double xb,const double yb,const double xe,const double ye){
  section_t* new_section = malloc(sizeof(section_t));

  new_section->xb = xb;
  new_section->xe = xe;
  new_section->yb = yb;
  new_section->ye = ye;

  return new_section;
}

double howLong(const section_t* section){
return sqrt(pow(section->xe-section->xb,2) + (section->ye-section->yb,2));
}

section_t* whichLonger(section_t* a, section_t* b){
    if(howLong(a) > howLong(b)) return a;
    else if(howLong(a)<howLong(b)) return b;

    printf("Odcinki sa rowne.");
    return a;
}

void saveSection(const char *path,int howMuch, const section_t* section){
  FILE *fp = fopen(path,"wb");

  fwrite(section,sizeof(section_t),howMuch,fp);

  fclose(fp);
}

section_t* loadSection(const char* path, int howMuch){
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

point_t* intersection(const section_t* a, const section_t* b){
  double a1,b1,a2,b2;
  point_t* point = malloc(sizeof(point_t));
//  y = ax + b;
//a = tg((y2-y1)/(x2-x1))
a1 = tan((a->ye - a->yb)/(a->xe-a->xb));
b1 = a->yb - a1*a->xb;
a2 = tan((b->ye - b->yb)/(b->xe-b->xb));
b2 = b->yb - b1*b->xb;

//a1x + b1 = a2x + b2
//x(a1-a2) = b2 - b1
//x = (b2 - b1)(a1-a2)

if(a1 == a2) return NULL;
else{
point->x = (b2 - b1)/(a1-a2);
point->y = a1*point->x + b1;
return point;
}
}

void display(section_t* section){
    section->xb = printf("x1 = %.2f\n",section->xb);
    section->yb = printf("y1 = %.2f\n",section->yb);
    section->xe = printf("x2 = %.2f\n",section->xe);
    section->ye = printf("y2 = %.2f\n",section->ye);

}

int main(){
  int n;
  srand((unsigned int)time(NULL));
//   section_t* section1 = new_section(5,6,10,12);
//   section_t* section2 = new_section(1,2,14,15);
//
// printf("Dlugosc odcinka: %.2f\n",howLong(section1));
// printf("Dlugosc odcinka: %.2f\n",howLong(section2));
//
// section_t* section =  whichLonger(section1, section2);
// printf("Dlugosc dluzszego odcinka: %.2f",howLong(section));

printf("Podaj liczbe odcinkow, które mają zostać utworzone: ");
scanf("%d",&n);

section_t* section = malloc(sizeof(section_t)*n);

for(int i=0; i<n; i++){
  section[i].xb = rand()%100;
  section[i].xe = rand()%100;
  section[i].yb = rand()%100;
  section[i].ye = rand()%100;
}

saveSection("section1.txt",n,section);
section_t* loadedSection = loadSection("section1.txt",n);
printf("Wczytany odcinek z pliku:\n");
display(loadedSection);


section_t* sortedSections = sort(section, n);

printf("Posortowane dlugosci odcinkow:\n");
for(int i=0; i<n; i++)
  printf("%.2f\n",howLong(&sortedSections[i]));

point_t*  point = malloc(sizeof(point_t));
point = intersection(&section[0],&section[1]);

printf("Punkt przeciecia dwoch odcinkow: \n");
printf("Odcinek pierwszy: \n");
display(&section[0]);
printf("Odcinek drugi: \n");
display(&section[1]);
if(point == NULL) printf("Brak punktu przeciecia lub nieskonczenie wiele");
else printf("Punkt przeciecia: (%.2f,%.2f)",point->x,point->y);

  return 0;
}
