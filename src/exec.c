#include "mash.h"
void exec(char **argv){
    pid_t pid;
    int status;
    if((pid = fork()) == 0){
        if (execvp(*argv, argv) < 0){
            printf("Error: No command -->%s\n<--", argv[0]);
        }
    } else if (pid < 0){
        printf("Error, %s failed\n", argv[0]);
    } else {
        while (wait(&status) != pid);
    }
}
