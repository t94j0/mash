#include "mash.h"
char *readline(){
  int p = 0;
  char *buffer = malloc(sizeof(char) * BUFFER_SIZE);
  int next_character, next_buffer = 1;
  if(!buffer){
    fprintf(stderr, "mash: allocation error\n");
    exit(1);
  }
  while(1){
    next_character = getchar();

    if(next_character == EOF || next_character == '\n'){
      buffer[p] = '\0';
      return buffer;
    } else {
      if(next_character == '\t'){
        //Do an ls command
        char *test = "ls";
        char **shit = &test;
        exec(shit);
      } else {
        buffer[p] = next_character;
      }
    }
    p++;

    if(p > BUFFER_SIZE){
      next_buffer = BUFFER_SIZE * ((next_buffer/BUFFER_SIZE) + 1);
      buffer = realloc(buffer, next_buffer);
      if(!buffer){
        fprintf(stderr, "mash: allocation error\n");
        exit(1);
      }
    }
  }
}
