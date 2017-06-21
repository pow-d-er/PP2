#include "zadanie1.h"

int* get_table_size(const char* path){
  FILE* fp = fopen(path,"rb");
  int *table_size = malloc(sizeof(int)*2);
  if(fp){
    for(int i=0; i<2; i++)
    fscanf(fp,"%d",&table_size[i]);
  }
  fclose(fp);
return table_size;
};

int **load_tab(const char* path, int* size){
    FILE* fp = fopen(path,"rb");
    int n;
    int **table = malloc(sizeof(int*)*size[0]);
      for(int i=0; i<size[1];i++)
        table[i] = malloc(sizeof(int)*size[1]);

        fscanf(fp,"%d",&n);
        fscanf(fp,"%d",&n);
    if(fp){
      for(int i=0; i<size[0]; i++)
        for(int j=0; j<size[1]; j++)
      fscanf(fp,"%d",&table[i][j]);
    }
    fclose(fp);
  return table;
};

int **sum(int** first, int** second,  int* size){
  int **summary = malloc(sizeof(int)*size[0]);
  for(int i=0; i<size[0]; i++)
  summary[i] = malloc(sizeof(int)*size[1]);

  for(int i=0; i<size[0]; i++)
    for(int j=0; j<size[1]; j++)
      summary[i][j] = first[i][j] + second[i][j];

  return summary;
};

int **subtract(int** first, int** second,  int* size){
    int **sub = malloc(sizeof(int)*size[0]);
    for(int i=0; i<size[0]; i++)
    sub[i] = malloc(sizeof(int)*size[1]);

    for(int i=0; i<size[0]; i++)
      for(int j=0; j<size[1]; j++)
        sub[i][j] = first[i][j] - second[i][j];

    return sub;
};


int row_average(int** tab, int row,  int* size){

  int row_avg = 0;

  for(int i=0; i<size[1]; i++)
    row_avg += tab[row][i];

  return row_avg/3;

};


int column_average(int** tab,int column,  int* size){
    int column_avg = 0;

    for(int i=0; i<size[1]; i++)
      column_avg += tab[i][column];

    return column_avg/3;
};
void display(int **tab, int* size){

printf("\n");
for(int i=0; i<size[0]; i++){
  for(int j=0; j<size[1]; j++){
    printf("%d\t", tab[i][j]);
  }
  printf("\n");
}

};
