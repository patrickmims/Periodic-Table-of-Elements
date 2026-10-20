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

typedef struct
{
    char *response;
    size_t size;
} memory_t;

static size_t write_callback(char *data, size_t size, size_t nmemb, void *client)
{
    char *ptr = NULL; 
    size_t realsize = nmemb;

    memory_t m;
    memory_t *memory = NULL;
    memory = &m;

    memory = (memory_t *)client;

    if((ptr = realloc(memory->response, memory->size + realsize + 1)) == NULL) 
        fprintf(libcurl_error_log(), "Error: ptr");

    memory->response = ptr;
    memcpy(&(memory->response[memory->size]), data, realsize);
    memory->size += realsize;
    memory->response[memory->size] = 0;

    return realsize;
}

void *curl_http_write()
{
    libcurl_t lc;
    memory_t memory; 

    if((lc.curl == curl_easy_init()) == NULL)
        fprintf(libcurl_error_log(), "Error: void curl_http_write()");

    curl_easy_setopt(lc.curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(lc.curl, CURLOPT_WRITEDATA, (void *)&memory);

    lc.code = curl_easy_perform(lc.curl);
    free(memory.response);
    curl_easy_cleanup(lc.curl);
}

void *curl_http()
{
    char remote_url[] = "https://api.periodictableofelements.org/elements/22/";

    libcurl_t libcurl;
    libcurl_t *lc = &libcurl;

    lc = (libcurl_t *)memory();

    lc->code = curl_global_init(CURL_GLOBAL_ALL);

    if(lc->code != CURLE_OK) // CURLE_OK is 0
        exit(EXIT_FAILURE);

    if((lc->curl = curl_easy_init()) == NULL)
        fprintf(stderr, "Error: libcurl_http");

    curl_easy_setopt(lc->curl, CURLOPT_URL, remote_url);

    if(lc->code = curl_easy_perform(lc->curl) != CURLE_OK)  // checks for 1, true
        exit(EXIT_FAILURE);

    curl_easy_cleanup(lc->curl);
    curl_global_cleanup();

    exit(EXIT_SUCCESS);
}
