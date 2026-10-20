#ifndef PT_H
#define PT_H

#include <arpa/inet.h>
#include <curl/curl.h>
#include <json-c/json.h>
#include <libssh2.h>
#include <libssh2_sftp.h>
#include <mysql.h>
#include <mysqld_error.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>

#include "lc.h"

typedef struct
{
    const char *authentication;
    const char *fingerprint;
    int i;
    int password;
    int rc;
    libssh2_socket_t sock;
    struct sockaddr_in sin;
    uint32_t hostaddr;
} sftp_t;

typedef struct
{
    const char *password;
    const char *path;
    const char *privatekey;
    const char *publickey;
    const char *user;
} config_t;

void create_process(pid_t, pthread_t);
void create_thread(pthread_t, void *(*)(), void *);

// sftp
void *sftp();

#endif
