#ifndef zadanie1_h
#define zadanie1_h

#include <stdio.h>
#include <stdlib.h>

int* get_table_size(const char* path);
int **load_tab(const char* path, int* size);
int **sum(int** first, int** second,int* size);
int **subtract(int** first, int** second,int* size);
int row_average(int** tab, int row,int* size);
int column_average(int** tab,int column,int* size);
void display(int **tab, int* size);

#endif
