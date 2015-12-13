#ifndef STD
#define STD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#endif

#ifndef INPUT_H
#define BUFFER_SIZE 2048
#define INPUT_H
char* readline();
#endif

#ifndef TOKENIZER_H
#define TOKENIZER_H
char** tokenizer(char *cmd);
#endif

#ifndef EXEC_H
#define EXEC_H
int exec(char **argv);
#endif

#ifndef TERM_COLORS
#define TERM_COLORS
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"
#endif
