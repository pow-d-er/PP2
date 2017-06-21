#include "zadanie1.h"

int main(int argc, char* argv[]){

int **tab1 = load_tab(argv[1], get_table_size(argv[1]));
int **tab2 = load_tab(argv[2], get_table_size(argv[2]));

display(tab1,get_table_size(argv[1]));

printf("Dodawanie: \n");
display(sum(tab1, tab2, get_table_size(argv[1])), get_table_size(argv[1]));

printf("Odejmowanie: \n");
display(subtract(tab1, tab2, get_table_size(argv[1])), get_table_size(argv[1]));

printf("\nŚrednia liczb rzędu 3: %d\n",row_average(tab1,2,get_table_size(argv[1])));
printf("\nŚrednia liczb kolumny 3: %d\n",column_average(tab1,2,get_table_size(argv[1])));

for(int i=0; i<get_table_size(argv[1])[1] ; i++){
  free(tab1[i]);
  free(tab2[i]);
}

free(tab1);
free(tab2);


  return 0;
}
