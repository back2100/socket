/**
 * @file  client to server peer to peer chat
 * @brief 
 * @author yuanchengbin ()
 * @date 2024-04-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "client.h"

#include "common.h"
#include <arpa/inet.h>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <netinet/in.h>

static int sockfd = 0;

int
main(int argc, char[] argv) {

    char sendbuf[MAXLINE] = {0};
    char recbuf[MAXLINE] = {0};

// no.1 creat socket
    sockfd = ::socket(AF_INET, SOCK_STREAM, 0);

// no.2 init connect state and connect
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htonl(chat_room_port);
    addr.sin_addr.s_addr = inet_addr(chat_room_ip);

    if(connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        printf("connect failed! error : %s \n", stderr(errno));
        exit(0);
    }

// no.3 write and read  
    while (1) {
        printf("-> please send message to server : \n");
        fgets(sendbuf, sizeof(sendbuf), stdin);\
        if(send(sockfd, sendbuf, strlen(sendbuf), 0) == -1) {
            // error
        }

        if(recv(sockfd, recbuf, sizeof(recbuf), 0) < 0) {
            // error
        }
        printf("-> %s \n", recbuf);
    }
    return 0;
}
