#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>  // For close()

int main() {
    int socket_desc;
    struct sockaddr_in server;
    char message[100], buf[100];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_desc == -1) {
        printf("Error in socket creation\n");
        return 1;
    }

    // Configure server details
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(3003); // Use htons() to convert to network byte order


    // Get input from user
    printf("Enter message to send: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; // Remove trailing newline

    // Send message to server
    if (sendto(socket_desc, message, strlen(message), 0 , (struct sockaddr *)&server , sizeof(server)) == -1) {
        printf("Error in sending message\n");
        return 1;
    }

    printf("Message sent to server\n");

    close(socket_desc); // Close the socket
    return 0;
}

