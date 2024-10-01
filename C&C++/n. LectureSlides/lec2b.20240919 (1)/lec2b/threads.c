//charcount.c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void* charcount(void *vargp);

int main() {
    pthread_t tid = pthread_self();
    printf("main: %u\n", (unsigned int)tid);

    while(1) {
        char str[100];
        pthread_t tid;
        scanf("%99s", str);
        if(strcmp(str, "quit") == 0)
            break;
        pthread_create(&tid, NULL, charcount, strdup(str));
    }
    return 0;
}

void* charcount(void *vargp) {
    char *str = (char*)vargp;
    int count[256] = {0,};
    pthread_t tid = pthread_self();
    int i;

    pthread_detach(tid);
    printf("server %u\n", (unsigned int)tid);
    for(i = 0; str[i]; i++)	
        count[ str[i] ]++; // Counting the occurrence of each char
    for(i = 0; i < 256; i++) {
        if(count[i] > 0)
            printf("%u: '%c': %d\n", (unsigned int)tid, i, count[i]);
    }

    free(str);
    return NULL;
}

