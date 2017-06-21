#include "zespolone.h"

int main(){

tab_t* table = create_new_tab(5);

add_to_tab(table, create_new(3,4));
add_to_tab(table, create_new(50,30));
add_to_tab(table, create_new(2,2));
add_to_tab(table, create_new(9,12));
add_to_tab(table, create_new(1,1));

add_to_tab(table, create_new(11,13));

display_tab(table);

printf("Posortowana tablica: \n");
 display_tab(sort(table));

 printf("\nNajmniejsza: "); display(find_min(table));
 printf("\nNajwieksza: "); display(find_max(table));

free(table);

  return 0;
}
