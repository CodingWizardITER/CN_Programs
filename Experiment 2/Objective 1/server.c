#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main()
{

    int listenfd, connfd, len, n;
    int buff;
    struct sockaddr_in servaddr, cliaddr;
    len = sizeof(servaddr);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(listenfd, (struct sockaddr *)&servaddr, len);
    getsockname(listenfd, (struct sockaddr *)&servaddr, &len);
    printf("Port for client=%ld\n", (long)ntohs(servaddr.sin_port));
    listen(listenfd, 5);
    connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &len);
    printf("Server received the message =%d\n", buff);
    printf("Enter a number for client : ");
    scanf("%d", &buff);
    write(connfd, &buff, sizeof(buff));
    return 0;
}