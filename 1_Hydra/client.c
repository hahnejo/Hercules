// creation of socket
// means of connection
// send and receive

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 4242
#define MAX 1024

void    chat(int socket_fd)
{
    char buf[MAX];
    // char user_response[MAX];
    int n;
    while (1)
    {
        memset(buf, '0', sizeof(buf));
        printf("What would you like to say?\n");
        scanf("%s", buf);
        if (buf[0])
        {
            n = 0;
            while ((buf[n++] = getchar()) != '\n') 
                ; 
            write(socket_fd, buf, sizeof(buf));
            memset(buf, '0', sizeof(buf));
            read(socket_fd, buf, sizeof(buf));
            printf("Server says : %s\n", buf);
        }
        if (strcmp(buf, "exit") == 0)
        {
            printf("Good bye!\n");
            break ;
        }    
    }
}

int     main(int argc, char **argv)
{
    struct sockaddr_in address;
    struct sockaddr_in server_address;
    int sock = 0;
    int val_read;
    char buf[MAX] = {0};
    char *tmp_arg = "Hello I am a client. Nice to meet you.\n";
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("socket initialization failed\n");
        return (-1);
    }

    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) < 0)
    {
        printf("invalid address\n");
        return (-1);
    }
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        printf("connection failed\n");
        return (-1);
    }
    send(sock, tmp_arg, strlen(tmp_arg), 0);
    printf("messege sent\n");
    val_read = read(sock, buf, MAX);
    printf("%s\n", buf);
    return (0);
}