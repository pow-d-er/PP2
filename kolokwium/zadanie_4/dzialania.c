#include "dzialania.h"


float calculate(float a, float b, type calc){

  return calc(a,b);
};


float sum(float a, float b){
  return a+b;
}

float subtract(float a, float b){
  return a-b;
}

float multiply(float a, float b){
  return a*b;
}

float division(float a, float b){
  if(b == 0) printf("Nie mozna dzielic przez 0");
  return a/b;

}
