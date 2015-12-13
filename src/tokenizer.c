#include "mash.h"
char **tokenizer (char *raw_input){
  char **input_arr = malloc(sizeof(&raw_input));
  //Hopefully no one goes over 256 arguments!!
  char *args[256];
  int i = 0;

  char *token = strtok(raw_input, " ");
  while(token != NULL){
    input_arr[i] = token;
    token = strtok(NULL, " ");
    i++;
  }
  return input_arr;
}
