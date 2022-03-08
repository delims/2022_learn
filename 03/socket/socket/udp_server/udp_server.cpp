//
//  udp_server.cpp
//  socket
//
//  Created by delims on 2022/3/7.
//

#include "udp_server.hpp"
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void run_udp_server() {
    int server_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); //最后一个参数写0可以自动匹配
    if (server_sock > 0) {
        printf("socket create success: %d \n",server_sock);
    } else return;
    sockaddr_in addr_in;
    addr_in.sin_family = AF_INET;
    addr_in.sin_port = htons(12345);
    addr_in.sin_addr.s_addr = htonl(INADDR_ANY); //自动获取IP
//    addr_in.sin_addr.s_addr = 0; //htonl(INADDR_ANY) 就 等于 0
    socklen_t socklen = sizeof(addr_in);
    int result =  0;
    
    result = bind(server_sock, (sockaddr*)&addr_in, socklen);
    if (result == 0) {
        printf("bind success \n");
    } else {
        printf("bind failure: %s \n",strerror(errno));return;
    }
    
    while (1) {
        sockaddr_in client_addr_in;
        socklen_t client_addr_len = sizeof(client_addr_in);
        char buffer[1024] = {0};
        char send_buffer[512] = "server received ~";
//        int size = recvfrom(server_sock, buffer, sizeof(buffer), 0, (sockaddr*)&client_addr_in, &client_addr_len);
        ssize_t size = recvfrom(server_sock, buffer, sizeof(buffer), 0, (sockaddr*)&client_addr_in, &client_addr_len);
        if (size < 0) {
            printf("recvfrom failure: %s \n",strerror(errno));return;
        }
//        printf("%s\n",buffer);
        printf("ip:%s  port: %d \n",inet_ntoa(client_addr_in.sin_addr),client_addr_in.sin_port);
        
        ssize_t send_size = sendto(server_sock, send_buffer, sizeof(send_buffer), 0, (sockaddr*)&client_addr_in, client_addr_len);
        
    }
    
    
}
