#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define IP "192.168.1.6"
#define PORT 45577

const char *e = "[-]";
const char *k = "[+]";

int client(void);

int main(void) {
    client();
    return EXIT_SUCCESS;


}

int client(void) {

    int client_socket;
    struct sockaddr_in server_addr;
    char response[256];

    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(IP);

    if(connect(client_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("%s Cannont connect server! :(\n", e);
        return EXIT_FAILURE;
    }

    recv(client_socket, &response, sizeof(response), 0);

    printf("%s Server sent data!\n Data: %s\n", k, response);

    close(client_socket);

    return EXIT_SUCCESS;
}
