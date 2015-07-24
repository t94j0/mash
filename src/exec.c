#include "mash.h"
void exec(char **argv){
    void new_process(char **argv);
    if(strcmp(argv[0], "cd") == 0){
        if(argv[1] == NULL){
            chdir(getenv("HOME"));
        } else {
            chdir(argv[1]);
        }
    } else if(strcmp(argv[0], "exit") == 0 || strcmp(argv[0], "quit") == 0){
        printf("good bye\n");
        exit(0);
    } else {
        new_process(argv);
    }
}
void new_process(char **argv){
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
