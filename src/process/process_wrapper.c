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
        case 0:  // execute the child process
            puts("create_process...");
            
            void *(*fn)(void *) = libcurl_http; // fn is run in the background
            // child inherits local variables - local to create_process(...)
            create_thread(thread, fn, head);
            break;
        default: 
            sleep(5);
            break;
    }
}
