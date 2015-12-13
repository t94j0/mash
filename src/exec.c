#include "mash.h"
int exec(char **argv){
  int new_process(char **argv);
  if(strcmp(argv[0], "cd") == 0){
    if(argv[1] == NULL){
      chdir(getenv("HOME"));
    } else {
      chdir(argv[1]);
    }
  } else if(strcmp(argv[0], "exit") == 0 || strcmp(argv[0], "quit") == 0){
    printf("good bye\n");
    exit(EXIT_SUCCESS);
  } else if(strcmp(argv[0], "help") == 0){
    //Display help
    printf("\nAvailable commands:\nexit - quits terminal\ncd - changes directory\nhelp - brings this menu");
    return 0;
  } else {
    //If ls is called, use --color
    if(strcmp(argv[0], "ls") == 0){
      int i;
      for(i = 0; argv[i] != '\0'; i++);
      argv[i] = "--color";
    }
    //Run the process with new_process
    if(new_process(argv) > 0){
      return 1;
    } else {
      return 0;
    }
  }

}

int new_process(char **argv){
  pid_t pid;
  int status;
  if((pid = fork()) == 0){
    if (execvp(*argv, argv) < 0){
      printf("Error: No command %s\n", argv[0]);
    }
  } else if (pid < 0){
    printf("Error, %s failed\n", argv[0]);
  } else {
    while (wait(&status) != pid);
  }
  return 1;
}
