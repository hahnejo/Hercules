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

int     create_socket(int socket_fd)
{
    if (socket_fd == -1)
    {
        printf("Cannot create a socket\n");
        return (-1);
    }
    return (0);
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
    struct sockaddr_in server;
    char buf[1024] = {0};
    addr_len = sizeof(server);
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (create_socket(socket_fd) == -1)
        return (-1);

    // remote server connection
    server.sin_addr.s_addr = inet_addr(INADDR_ANY);
    server.family = AF_INET;
    server.sin_port = htons(80);

    if (connect(socket_fd, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        printf("connection error\n");
        return (-1);
    }
    if (bind(socket_fd, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        printf("bind failed\n");
        return (-1);
    }
    if (listen(socket_fd, 3) < 0)
    {
        printf("listen failed\n");
        return (-1);
    }
    new_socket = accept(socket_fd, (struct sockaddr *)&server, (socklen_t *)&addr_len);
    if ((new_socket < 0)
    {
        printf("accept failed\n");
        return (-1);
    }
    val_read = read()
    printf("connected\n");
    return (0);
}