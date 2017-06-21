#include "zespolone.h"

int main(){

zespolona_t* a = create_new(5,10);
zespolona_t* b = create_new(7,3);

display(a);
display(b);

printf("Suma:\n");
display(sum(a,b));
printf("\n");

printf("Odejmowanie:\n");
display(subtract(a,b));
printf("\n");

printf("Mnozenie:\n");
display(multiply(a,b));
printf("\n");

printf("Modul liczby "); display(a); printf(" wynosi: %.2f\n",calculate_mod(a));

printf("\n\n");
printf("Zapisuje liczbe: "); display(a);
save("zespolona.txt",a);
printf("\nWczytana liczba: ");display(load("zespolona.txt"));

free(a);
free(b);


  return 0;
}
