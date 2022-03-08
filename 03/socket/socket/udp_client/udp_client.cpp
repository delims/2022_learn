//
//  udp_client.cpp
//  socket
//
//  Created by delims on 2022/3/7.
//

#include "udp_client.hpp"
#include <netinet/in.h>
#include <netinet/udp.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

void run_udp_client() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    sockaddr_in addr_in;
    addr_in.sin_family = AF_INET;
    addr_in.sin_port = htons(12345);
    addr_in.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    socklen_t len = sizeof(addr_in);
    const char *msg = "hello world ";
    char buffer[1024] = {0};
    char recv_buffer[1024] = {0};
    memcpy(buffer, msg, strlen(msg) + 1);
    while (1) {
        ssize_t size = sendto(sock, buffer, strlen(msg) + 1, 0, (sockaddr*)&addr_in, len);
        
        printf("send bytes count: %03zu\n",size);
        sleep(1);

        ssize_t recv_size = recvfrom(sock, recv_buffer, sizeof(recv_buffer), 0, (sockaddr*)&addr_in, &len);
 
        printf("received : %s\n",recv_buffer);

    }
}
