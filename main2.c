//Author: Enzo Ciccarelli-Asta
#include <stdio.h>
#include <gensnd.h>

//gensine executable
//requests a 10 digit telephone number, in format <##########>
//prints the DTMF tone of those 10 digits in sequence
//250 ms of silence inbetween each
int main(int argc, char const *argv[]) {
  FILE *f;
  f = fopen("gendial.txt", "w");
  char number[11];
  printf("Please input a 10-digit telephone number.\n");
  fgets(number, 11, stdin);
  for(int i = 0; i < 10; i++){
    keypress(number[i], f);
    if(i != 9) silence(8000, .25, f);
  }
  fclose(f);
  return 0;
}
