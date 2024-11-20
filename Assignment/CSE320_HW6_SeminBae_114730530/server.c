//echo_server.c
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include "util.h"


#define SERV_PORT   6000
#define MAXLINE     512

void echo(int fd) {
    // Initialize the file descriptor set for monitoring input sources
    fd_set readfds;

    // Buffer to store incoming or outgoing messages
    char line[MAXLINE];

    while(1) {
        // Clear all entries in the file descriptor set
        FD_ZERO(&readfds);
        // Add the client socket descriptor to the set
        FD_SET(fd, &readfds);
        // Add the standard input (keyboard input) descriptor to the set
        FD_SET(STDIN_FILENO, &readfds);

        // Determine the highest file descriptor value for select()
        // select() needs this to know how many descriptors to check
        int maxfd = (fd > STDIN_FILENO) ? fd : STDIN_FILENO;

        // Wait for any of the file descriptors to become ready for reading
        // select() blocks until at least one descriptor is ready
        int ready = select(maxfd + 1, &readfds, NULL, NULL, NULL);
        
        // If select() returns a negative value, an error occurred
        CHKBOOLQUIT(ready >= 0, "select error");

        // Check if the client socket is ready for reading
        if (FD_ISSET(fd, &readfds)) {

            // Read data from the client socket
            int n = readline(fd, line, MAXLINE);

            // If readline() fails, terminate the process
            CHKBOOLQUIT(n >= 0, "readline error");

            // If the client has closed the connection (n == 0), exit the loop
            if (n == 0)
                return;

            // if client send "exit" line, then terminate program
            if (strcmp(line, "exit\n") == 0) {
                printf("Program terminating since client said 'exit'\n");
                close(fd);  // close the client socket
                kill(getppid(), SIGTERM); // signal SIGTERM to exit parent's process
                exit(0);    // exit child process
            }
            // if client send the string that has 50 > length, then terminate program
            else if(strlen(line) > 50){
                printf("Program terminating since client send string that has 50 > length.\n");
                close(fd);  // close the client socket
                kill(getppid(), SIGTERM); // signal SIGTERM to exit parent's process
                exit(0);    // exit child process
            }
            // if no error case, print line with Client said:
            else{
                printf("Client Said: %s", line);
            }
        }

        // Check if there is input from the server's standard input (keyboard)
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            int flag = 0; // flag if process will terminate

            // If input is available from the server's keyboard
            if (fgets(line, MAXLINE, stdin) != NULL) {
                // Get the length of the input line
                int n = strlen(line);

            // if Server send the string that has 50 > length, then terminate program
            if(n > 50){
                printf("Program terminating since Server sent string that has 50 > length.\n");
                strncat(line, "Program terminating since Server sent string that has 50 > length.\n", sizeof(line) - strlen(line) - 1);
                flag = 1; // flag true that process will terminate
            }
            // if Server send "exit" line, then terminate program
            else if (strcmp(line, "exit\n") == 0) {
            printf("Program terminating since Server said 'exit'\n");
            strncat(line, "Program terminating since Server said 'exit'\n", sizeof(line) - strlen(line) - 1);
            flag = 1; // flag true that process will terminate
            }

            // Recalculate `n` after modification
            n = strlen(line);

            // Write the input message to the client socket
            CHKBOOLQUIT(writen(fd, line, n) == n, "writen error");

            // if custom terminate flag on
            if(flag == 1){
                close(fd);  // close the client socket
                kill(getppid(), SIGTERM); // signal SIGTERM to exit parent's process
                exit(0);    // exit child process
                }
            }
        }
    }
}

// custom handling method to exit parent's process
void handle_sigterm(int sig) {
    printf("Server is shutting down.\n");
    exit(0);
}

int main(int argc, char **argv) {
    // initalize the SIGTERM sigal handler
    signal(SIGTERM, handle_sigterm);

    int sfd;
    struct sockaddr_in saddr;

    CHKBOOLQUIT( (sfd = socket(AF_INET, SOCK_STREAM, 0)) >= 0, "socket failed" );
    printf("Socket Successfully Connected\n");

    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(SERV_PORT);
    CHKBOOLQUIT( bind(sfd, (struct sockaddr*)&saddr, sizeof(saddr)) >= 0, "bind failed");
    printf("Socket Successfully Bounded\n");

    CHKBOOLQUIT( listen(sfd, 1024) >= 0, "listen failed" );
    printf("Socket is Listening\n");

    while(1) {
        struct sockaddr_in caddr;
        int cfd;
        unsigned int clen = sizeof(caddr);

        cfd = accept(sfd, (struct sockaddr*) &caddr, &clen);
        if (cfd < 0) {
            if (errno == EINTR) //
                break; // break loop if the SIGTERM signal accepted
            else
                CHKBOOLQUIT(0, "accept failed");
        }
        
        if(fork() == 0) {   //child processs
            printf("Socket Accepting Clinet Connection\n");
            close(sfd);
            printf("pid: %d, client: %s:%d\n", getpid(),
                                            inet_ntoa(caddr.sin_addr), caddr.sin_port);
            echo(cfd);
            printf("pid: %d done\n", getpid());
            exit(0);
        }
        else 
            close(cfd);
    }
    return 0;
}

