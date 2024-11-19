
#include <stdio.h>
#include <signal.h>
#include <unistd.h>



int sigStrlen(char *str) {
    int i;
    for(i = 0; str[i]; i++) ;
    return i;
}

void sigPuts(char *str) { write(1, str, sigStrlen(str)); }

void handler(int sig) { sigPuts("Caught SIGINT!\n"); }


int main() {
    signal(SIGINT, handler); //register handler
    sigset_t mask, oldmask; // prepare mask set
    sigemptyset(&mask);
    sigaddset(&mask, SIGINT);
    //Try Ctrl-C with and without this line
    sigprocmask(SIG_BLOCK, &mask, &oldmask);
    printf("Before sleep\n");
    sleep(3);
    printf("After sleep\n");
    sigprocmask(SIG_SETMASK, &oldmask, NULL);
    return 0;
}