#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int sock;
    struct sockaddr_in serv_addr;

    char reg_no[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

<<<<<<< HEAD
    inet_pton(AF_INET, "127.0.0.1",
              &serv_addr.sin_addr);

    if (connect(sock,
                (struct sockaddr *)&serv_addr,
                sizeof(serv_addr)) < 0)
    {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        printf("\nEnter Registration Number (or type bye): ");
        fgets(reg_no, BUFFER_SIZE, stdin);
        reg_no[strcspn(reg_no, "\n")] = 0;

        send(sock, reg_no, strlen(reg_no), 0);

        if (strcmp(reg_no, "bye") == 0)
        {
            printf("Connection closed.\n");
            break;
        }

        memset(buffer, 0, BUFFER_SIZE);

        read(sock, buffer, BUFFER_SIZE);

        printf("Server Response: %s\n", buffer);
    }

    close(sock);

    return 0;
}
=======
    // Convert IPv4 address from text to binary
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("invalid address");
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connection failed");
        return -1;
    }

    // Send message
    send(sock, "Hello from client!", strlen("Hello from client!"), 0);
    printf("Message sent\n");

    // Receive response
    read(sock, buffer, 1024);
    printf("Server says: %s\n", buffer);

    close(sock);
    return 0;
}
>>>>>>> e7f6de095cb0df4f918d77f678d3a5c2f2f25507
