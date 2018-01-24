//
// Created by 冷文昊 on 2017/12/20.
//

#ifndef __WHTCP_SERVER_H_
#define __WHTCP_SERVER_H_
//#include <stdio.h>
//#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
//#include <time.h>
//#include <string.h>
//#include <unistd.h>

class WHTcpServer
{
public:
    WHTcpServer();
    ~WHTcpServer();
    int myAccept();
private:
    int                 _socketFd;
    struct sockaddr_in  _addr;
//
};


#endif //DATASTRUCTUREGIT_WHTCPSERVER_H
