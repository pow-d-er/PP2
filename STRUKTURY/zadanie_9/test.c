#include "biblioteka.h"

int main(){

  library_t* first = new_library(10);

  add_record(first,"Piotr Proszowski", "dupa",2,997 );
  add_record(first,"Piotr Proszowski", "koziolek",2,997 );
  add_record(first,"Piotr Proszowski", "hehhehe",2,997 );
  add_record(first,"Piotr Proszowski", "gowo",2,997 );
  add_record(first,"Piotr Proszowski", "azgierz",2,997 );

  display(first);
  display(sort_by_title(first));

  return 0;
}
