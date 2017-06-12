#include "odcinki.h"


int main(){
  srand((unsigned int)time(NULL));
section_t* section = new_section(1,1,2,2);
section_t* section2 = new_section(1,1,4,4);
display(section);
printf("Odcinek ma dlugosc: %.2f\n",howLong(section));
printf("Dłuższy odcinek ma długość: %.2f\n",howLong(whichLonger(section,section2)));

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
int n;
printf("Podaj liczbe odcinkow jaka ma zostac utworzona: ");
scanf("%d",&n);

section_t* tab = malloc(sizeof(section_t)*n);

for(int i=0; i<n; i++)
  *(tab+i) = *new_section(rand()%20,rand()%20,rand()%20,rand()%20);

save_sections("sections.txt",n,tab);
section_t* loaded_sections = load("sections.txt",n);

printf("Pierwszy odcinek z zaladaowanej tablicy: \n");
display(&loaded_sections[0]);

printf("Posortowane odcinki wg. dlugosci: \n");
section_t* sorted_sections = sort(loaded_sections,n);
for(int i=0; i<n; i++)
printf("Odcinek%d: %.2f\n",i+1,howLong(&sorted_sections[i]));

section_t* a = new_section(1,1,5,5);
section_t* b = new_section(1,5,5,1);

point_t* intersection_point = intersection(a,b);
printf("Odcinki: \n");
printf("Odcinek1: \n");
display(a);
printf("Odcinek2: \n");
display(b);
printf("Ich punkt przeciecia to: (%.2f,%.2f)",
            intersection_point->x,intersection_point->y);
  return 0;
}
