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
    int sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(struct sockaddr_in);
    char recv_line[MAX_LINE + 1];
    char send_line[MAX_LINE + 1];
    FILE *logfile;
    int count = 0;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        if ((client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_len)) == -1) {
            perror("accept");
            continue;
        }

        logfile = fopen("/tmp/server9.log", "a");
        if (logfile == NULL) {
            perror("fopen");
            exit(1);
        }

        memset(recv_line, 0, MAX_LINE + 1);
        if (read(client_sockfd, recv_line, MAX_LINE) == -1) {
            perror("read");
            exit(1);
        }

        fprintf(logfile, "Received data: %s\n", recv_line);

        count = 0;
        int i;
        for (i = 0; recv_line[i] != '\0'; i++) {
            if (recv_line[i] == ' ') {
                count++;
            }
        }
        count++;

        sprintf(send_line, "Number of words: %d, Number of characters: %d", count, (int)strlen(recv_line));
        write(client_sockfd, send_line, strlen(send_line));

        fprintf(logfile, "Sent data: %s\n", send_line);
        fclose(logfile);

        close(client_sockfd);
    }

    close(sockfd);

    return 0;
}
