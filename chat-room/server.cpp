/**
 * @file server.cpp 
 * @brief 
 * @author yuanchengbin ()
 * @date 2024-04-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "server.h"
#include "client.h"
#include "common.h"
#include <cstdio>
#include <sys/socket.h>

static int sockfd = 0;

int
main(int argc, char** argv) {

    char sendbuf[MAXLINE] = {0};
    char recbuf[MAXLINE] = {0};

    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(0 > sockfd) {
        perror("socket failed");
        return -1;
    }

    struct sockaddr_in addr = {AF_INET};
    addr.sin_port = htons(chat_room_port);
    addr.sin_addr.s_addr = inet_addr(chat_room_ip);
    socklen_t addr_len = sizeof(addr);

    if(bind(sockfd, (struct sockaddr *)&addr, addr_len) < 0) {
        perror("bind");
        return -1;
    }

    return 0;
}