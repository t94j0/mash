#include "mash.h"
int main(int argc, char *topkek){
  //Have a pointer to the input and a pointer to the pointer of the input
  char *raw_input;
  char **pretty_input;
  int status;
  //Declare that there is an initialize function
  void init();
  //Run that initialize function
  init();
  //Start main loop
  do{
    //First, it shows that the user must input something
    printf(KRED "> " RESET);
    //Then we read the line from input
    raw_input = readline();
    //Once enter is pressed, we tokenize what the user typed in
    pretty_input = tokenizer(raw_input);
    //Then we execute what the user wanted to do
    status = exec(pretty_input);

    //Free space for the next go around
    free(raw_input);
    free(pretty_input);
  } while (status);
  return 0;
}

void init(){
  printf(KWHT "Welcome to mash. Use" KBLU " \"help\" " KWHT "to view available commands.\n" RESET);
}
