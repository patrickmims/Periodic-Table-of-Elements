#include "pt.h"

FILE process_error_log()
{
    FILE *filePtr = NULL;

    if((filePtr = fopen("error_log.txt", "a")) == NULL)
        exit(EXIT_FALURE);

    return filePtr;
}

void create_process(pid_t pid)
{
    switch(pid = fork())
    {
        case -1:
            fprintf(process_error_log(), "Error: process error...");
        case 0:
            create_thread();
        default: 
            sleep(5);
            break;
    }
}
