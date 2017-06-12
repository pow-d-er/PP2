#include "biblioteka.h"

int main(){

library_t* library = new_library(10);
add_record(library,"Kopernik Zdzisiek","O obrotach",4,2007);
add_record(library,"Grabowski Krzysiek","Gościu",7,1997);
add_record(library,"Kiełbasa Andrzej","Matematyka",4,2013);
add_record(library,"Łopata Stefan","Ergonomia",8,1985);
add_record(library,"Anand Ali","Szachy",6,1946);

display(library);
// printf("\nPosortowane po rodzaju książki: \n");
// display(sort_by_type(library));
// printf("\nPosortowane po roku wydania książki: \n");
// display(sort_by_year(library));
// printf("\nPosortowane po tytule książki: \n");
// display(sort_by_title(library));
printf("\nPosortowane po nazwie autora: \n");
display(sort_by_authorName(library));

  return 0;
}
