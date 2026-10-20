#include "pt.h"
#include "lc.h"

FILE *process_error_log()
{
    FILE *filePtr = NULL;

    if((filePtr = fopen("error_log.txt", "a")) == NULL)
        exit(EXIT_FAILURE);

    return filePtr;
}

void create_process(pid_t pid, pthread_t thread) // pass two parameters
{
    struct list *head = NULL;
    switch(pid = fork())
    {
        case -1:
            fprintf(process_error_log(), "Error: process error...");
        case 0:  // execute the child process
            puts("create_process...");
            
            // libcurl_http returns a pointer, hence *(*)()
            void *(*fn)(void *) = curl_http; // fn is run in the background
            // child inherits local variables - local to create_process(...)
            create_thread(thread, fn, head); // pass two arguments
            break;
        default: 
            sleep(5);
            break;
    }
}
