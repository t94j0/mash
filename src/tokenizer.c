#include "mash.h"
void tokenizer (char *cmd, char **argv){
    while(*cmd != '\0'){
        while(*cmd == ' ' || *cmd == '\t' || *cmd == '\n'){
            *cmd++ = '\0';
        }
        *argv++ = cmd;
        while(*cmd != '\0' && *cmd != ' ' && *cmd != '\t' && *cmd != '\n'){
            cmd++;
        }
    }
    *argv = '\0';
}
