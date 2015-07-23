#include <stdio.h>
#include "mash.h"
int main(int argc, char *topkek){
    char *argv[64];
    char command[1024];
    while(1){
        printf("> ");
        fgets(command, 1024, stdin);
        strtok(command, "\n");
        tokenizer(command, argv);
        if(strcmp(argv[0], "exit") == 0 || strcmp(argv[0], "quit") == 0){
            return 0;
        } else if(strcmp(argv[0], "cd") == 0){
            chdir(argv[1]);
        } else if(strcmp(argv[0], "whatsthebestshell") == 0){
            printf("zsh, this one is horse shit.\n");
        } else {
            exec(argv);
        }
    }
    return 0;
}
