#define BUFFER_SIZE 1024
#include "mash.h"
int main(int argc, char *topkek){
    void init();
    char *buffer = malloc(sizeof(char) * BUFFER_SIZE);
    char pos;
    char c;
    init();
    while(1){
        //Set variables to zero
        tokenizer(command, argv);
        exec(argv);
    }
    return 0;
}

void init(){
    printf(KWHT "Welcome to mash. Use" KBLU " \"help\" " KWHT "to view available commands.\n" RESET);
}
