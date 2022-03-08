//
//  tcp_client.cpp
//  socket
//
//  Created by delims on 2022/3/7.
//

#include "tcp_client.hpp"
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int run_tcp_client () {
    sockaddr_in server_addr_in;
    server_addr_in.sin_family = AF_INET;
    server_addr_in.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr_in.sin_port = htons(16536);
    
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    int con_ret = 1;
    int number = 0;
    while (con_ret) {
        con_ret = connect(sock, (sockaddr*)&server_addr_in, sizeof(server_addr_in));
        if (con_ret != 0) {
            printf("connnet error: %s \n",strerror(errno));
            sleep(1);
        }
    }
    
//    const char *str = "hello delims \n";
    char buffer[1024] = {0};
    while (1) {
        sprintf(buffer, "% 6d\n",number++);
        write(sock, buffer, strlen(buffer));
        printf("%s ",buffer);
        usleep(100);
    }
}
