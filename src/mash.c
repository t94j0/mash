#include "mash.h"
int main(int argc, char *topkek){
    char *argv[64];
    char command[1024];
    int command_index, i;
    char temp;
    while(1){
        //Set variables to zero
        command_index = 0;
        temp = '\0';
        for(i = 0; i < sizeof(command); i++){
            command[i] = '\0';
        }

        printf(KRED "> " RESET);

        while((temp = fgetc(stdin)) != '\n'){
            if(temp == '~'){
                strcpy(stdin, "/home/maxh/");
            } else {
                command[command_index++] = temp;
            }
            temp = '\0';
        }

        tokenizer(command, argv);
        exec(argv);
    }
    return 0;
}
