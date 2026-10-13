#ifndef PT_H
#define PT_H

#include <curl/curl.h>
#include <json-c/json.h>
#include <mysql.h>
#include <mysqld_error.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

void create_process(pid_t);

#endif
