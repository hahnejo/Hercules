// creation of socket

// creating a socket == specify its address family
// AF_INET is one of the address families

// set socket
// bind
// listen
// accept

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 4242
#define MAX 1024

int     create_socket(int socket_fd)
{
    if (socket_fd == -1)
    {
        printf("Cannot create a socket\n");
        return (-1);
    }
    return (0);
}

void    chat(int socket_fd)
{
    char buf[MAX];
    int n;
    while (1)
    {
        memset(buf, '0', MAX);
        read(socket_fd, buf, sizeof(buf));
        printf("client says : %s\n", buf);
        memset(buf, '0', MAX);
        n = 0;
        while ((buf[n++] = getchar()) != '\n')
            ;
        if (strcmp("exit", buf) == 0)
        {
            printf("adios!\n");
            break;
        }
    }
}

// socket ( addr family, type, protocol )
// SOCK_STREAM = connection oriented TCP protocol

// inet_addr is handy. why? converts IP to long format.
// then put that into server.sin_addr.s_addr

int     main(int argc, char **argv)
{
    int socket_fd;
    int new_socket;
    int addr_len;
    int val_read;
    char *temp_arg = "Hello! I am server. Nice to meet you.\n";
    struct sockaddr_in address;
    char buf[MAX] = {0};
    addr_len = sizeof(address);
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (create_socket(socket_fd) == -1)
        return (-1);

    // remote server connection
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);

    // if (connect(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    // {
    //     printf("connection error\n");
    //     return (-1);
    // }
    if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        printf("bind failed\n");
        return (-1);
    }
    if (listen(socket_fd, 3) < 0)
    {
        printf("listen failed\n");
        return (-1);
    }
    new_socket = accept(socket_fd, (struct sockaddr *)&address, (socklen_t *)&addr_len);
    if (new_socket < 0)
    {
        printf("accept failed\n");
        return (-1);
    }
    // printf("%s\n", buf);
    // send(new_socket, temp_arg, strlen(temp_arg), 0);
    printf("connected\n");
    chat(socket_fd);
    close(socket_fd);
    return (0);
}