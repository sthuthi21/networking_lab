#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>  // For close()

#define PORT 3003
#define BUF_SIZE 100

int main() {
    int socket_desc;
    struct sockaddr_in server, client;
    char buf[BUF_SIZE];
    socklen_t len = sizeof(client);

    // Create UDP socket
    socket_desc = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_desc == -1) {
        printf("Error in socket creation\n");
        return 1;
    }

    // Configure server address
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the socket
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error in binding\n");
        return 1;
    }

    printf("Server is waiting for messages...\n");

    // Receive message
    int k = recvfrom(socket_desc, buf, BUF_SIZE, 0, (struct sockaddr *)&client, &len);
    if (k == -1) {
        printf("Error in receiving message\n");
        return 1;
    }

    buf[k] = '\0';  // Null terminate the received string
    printf("Message received from client: %s\n", buf);

    close(socket_desc);
    return 0;
}

