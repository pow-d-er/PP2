#include "highscore.h"

int main(){

tab_highscore_t* tab = new_tab_highscore(5);
add_highscore(tab, "Pietros657", 25.5);
add_highscore(tab, "Q-Boss", 66.32);
add_highscore(tab, "Usmiechenty kalosz", 18.05);
add_highscore(tab, "lubie_placki", 57.35);
tab_highscore_t* sorted_tab = sort_highscores(tab);
display_highscores(tab);
printf("Posortowane wyniki: \n");
display_highscores(sorted_tab);

save_highscore("highscores.txt",sorted_tab);
printf("\nWczytane wyniki z pliku highscores.txt: \n");
display_highscores(load_highscore("highscores.txt"));
  return 0;
}
