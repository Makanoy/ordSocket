#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define IP  "192.168.1.6"
#define PORT 45566

int server(void);

int main(void) {
    server();
    return EXIT_SUCCESS;

}

int server(void) {
    int server_socket;
    int client_socket;
    struct sockaddr_in server_addr;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(IP);

    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_socket, 1);

    client_socket = accept(server_socket, NULL, NULL);

    return EXIT_SUCCESS;
}
