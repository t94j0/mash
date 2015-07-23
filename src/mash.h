#ifndef STD
    #define STD
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
#endif

#ifndef TOKENIZER_H
    #define TOKENIZER_H
    void tokenizer(char *cmd, char **argv);
#endif

#ifndef EXEC_H
    #define EXEC_H
    void exec(char **argv);
#endif
