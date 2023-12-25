#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"
#define MAX_LINE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char send_line[MAX_LINE + 1], recv_line[MAX_LINE + 1];
    FILE *logfile;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    logfile = fopen("/tmp/client9.log", "a");
    if (logfile == NULL) {
        perror("fopen");
        exit(1);
    }

    strcpy(send_line, "word1 word2 word3 word4");
    fprintf(logfile, "Sent data: %s\n", send_line);
    write(sockfd, send_line, strlen(send_line));

    memset(recv_line, 0, MAX_LINE + 1);
    if (read(sockfd, recv_line, MAX_LINE) == -1) {
        perror("read");
        exit(1);
    }

    fprintf(logfile, "Received data: %s\n", recv_line);
    fclose(logfile);

    close(sockfd);

    return 0;
}
