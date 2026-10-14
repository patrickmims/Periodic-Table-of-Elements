#include "pt.h"

FILE *libcurl_error_log()
{
    FILE *ptr = NULL;

    if((ptr = fopen("libcurl_error_log.txt", "a")) == NULL)
        fprintf(stderr, "Error:");

    return ptr;
}

void *memory()
{
    void *memory = NULL;

    if((memory = malloc(sizeof(void *))) == NULL)
        fprintf(libcurl_error_log(), "Error: allocating memory");

    return memory;
}

void *libcurl_http()
{
    libcurl_t libcurl;
    libcurl_t *lc = &libcurl;

    lc = (libcurl_t *)memory();

    return 
}
