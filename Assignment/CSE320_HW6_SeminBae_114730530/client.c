//echo_client.c
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include "util.h"

#define SERV_ADDR   "127.0.0.1"
#define SERV_PORT   6000
#define MAXLINE     512

void copy(int sfd) {
    char sline[MAXLINE], rline[MAXLINE];
    fd_set readfds; // File descriptor set for monitoring input and server

    while (1) {
        // Initialize the file descriptor set
        FD_ZERO(&readfds);

        // Add the server socket (sfd) to the set
        FD_SET(sfd, &readfds);

        // Add the standard input (keyboard) to the set
        FD_SET(STDIN_FILENO, &readfds);

        // Determine the highest file descriptor value for select()
        int maxfd = (sfd > STDIN_FILENO) ? sfd : STDIN_FILENO;

        // Wait for input from either the server or the user
        int ready = select(maxfd + 1, &readfds, NULL, NULL, NULL);
        CHKBOOLQUIT(ready >= 0, "select error");

        // Check if the server has sent a message
        if (FD_ISSET(sfd, &readfds)) {
            int n = readline(sfd, rline, MAXLINE); // Read message from the server
            CHKBOOLQUIT(n >= 0, "readline error");

            if (n == 0) // Server closed the connection
                return;

            rline[n] = 0; // Null-terminate the message

            printf("Server Said: ");
            fputs(rline, stdout); // Print the server's message to the console
        }

        // Check if the user has typed something
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            if (fgets(sline, MAXLINE, stdin) != NULL) { // Read user input
                
                // if client type 'exit' then print some log in client terminal
                if(strcmp(sline, "exit\n") == 0){  
                    printf("Program terminating since client said 'exit'\n");
                }
                // if clinet type > 50, then print log in client terminal
                else if(strlen(sline) > 50){
                    printf("Program terminating since client send string that has 50 > length.\n");
                }

                // get length of string
                int n = strlen(sline);
                CHKBOOLQUIT(writen(sfd, sline, n) == n, "writen error"); // Send to server
            }
        }
    }

    CHKBOOLQUIT(ferror(stdin) == 0, "cannot read file"); // Ensure no stdin errors occurred
}

int main(int argc, char **argv) {
    int sfd;
    struct sockaddr_in saddr;

    CHKBOOLQUIT( (sfd = socket(AF_INET, SOCK_STREAM, 0)) >= 0, "socket failed" );
    printf("Client successfully Connect to Server.\n");

    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr(SERV_ADDR);
    saddr.sin_port = htons(SERV_PORT);

    CHKBOOLQUIT( connect(sfd, (struct sockaddr*)&saddr, sizeof(saddr)) >= 0,
                 "connectfailed" );
    printf("server: %s:%d\n", inet_ntoa(saddr.sin_addr), saddr.sin_port);

    copy(sfd);

    close(sfd);
    return 0;
}
