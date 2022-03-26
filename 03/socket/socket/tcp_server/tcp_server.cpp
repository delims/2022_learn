//
//  tcp_server.cpp
//  tcp_server
//
//  Created by delims on 2022/3/7.
//

#include "tcp_server.hpp"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int run_tcp_server(){
    //
    int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    sockaddr_in addr_in;
//    sockaddr_in6 addr_in6;
    addr_in.sin_family = AF_INET;
    addr_in.sin_port = htons(3000);
//    addr_in.sin_addr.s_addr = htonl(INADDR_ANY); //自动获取IP地址，或者使用指定IP地址
    addr_in.sin_addr.s_addr = inet_addr("127.0.0.1");

    int tr = 1;
    int result = 0;
    printf("socket created: %d \n",server_socket);
    
    result = setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &tr, sizeof(tr));
    if (result == 0) {
        printf("setsockopt success\n");
    } else return 0;
    
    result = bind(server_socket, (struct sockaddr*)&addr_in, sizeof(addr_in));
    if (result == 0) {
        printf("bind success\n");
    } else return 0;
    
    result = listen(server_socket, 20);
    if (result == 0) {
        printf("listen success\n");
    } else return 0;
    
    sockaddr_in client_sockaddr_in;
    socklen_t client_sock_len = sizeof(client_sockaddr_in);
    while (1) {
        printf("begin accept ...\n");
        int client_socket = accept(server_socket, (struct sockaddr*)&client_sockaddr_in, &client_sock_len);
        printf("client coming ...\n");
        
        while (1) {
            char buffer[1024] = {0};
            ssize_t size = read(client_socket, buffer, 1024);
//            printf("receive bytes lenth = %ld \n",size);
            printf("%s ",buffer);
            memset(buffer, '\0', 1024);
            if (size == -1) {
                printf("error: %s \n",strerror(errno));
                printf("connet lost  %d  %d\n",close(client_socket),close(server_socket));
                return 0;
            }
            
//            sleep(10);
            usleep(100);
        }
        /**
        close(client_socket);// //硬生生的断开套接字，无法发送也无法接收
        shutdown(client_socket, SHUT_WR);//断开发送，执行后不能 write
        shutdown(client_socket, SHUT_RD);//断开读取。执行后不能 read
        shutdown(client_socket, SHUT_RDWR);// 断开发送和接受，等同于 close(); */
    }
}
