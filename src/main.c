#include "pt.h"
#include "lc.h"

int main(int argc, char **argv)
{
    puts("Periodic table of Elements");

    pid_t pid;
    pthread_t thread;

    create_process(pid, thread);

    return 0;
}
