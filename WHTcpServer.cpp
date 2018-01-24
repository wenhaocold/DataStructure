//
// Created by 冷文昊 on 2017/12/20.
//
#include <sys/socket.h>
#include <stdio.h>
#include "WHTcpServer.h"

WHTcpServer::WHTcpServer()
{
    _addr.sin_family        = AF_INET;
    _addr.sin_port          = htons(9999);
    _addr.sin_addr.s_addr   = htonl(INADDR_ANY);
    _socketFd =  socket(AF_INET, SOCK_STREAM, 0);
    bind(_socketFd, (struct sockaddr*)&_addr, sizeof(_addr));// == -1
    listen(_socketFd, 10);
}

int WHTcpServer::myAccept()
{
    struct sockaddr_in clientAddr;
    socklen_t length;
    if (accept(_socketFd, (struct sockaddr*)&clientAddr, &length) < 0)
    {
        printf("error\n");
    }
    else
    {
        printf("success\n");
    }
}

WHTcpServer::~WHTcpServer()
{

}