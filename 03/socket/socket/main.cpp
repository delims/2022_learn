//
//  main.cpp
//  socket
//
//  Created by delims on 2022/3/7.
//

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h> // IPPROTO_TCP 等协议定义
#include <arpa/inet.h> // 字节序转换相关函数
#include <netinet/tcp.h>
#include <unistd.h>
#include <vector>

extern void run_udp_server();
extern void run_tcp_client();
extern int run_tcp_server();

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%s\n",argv[0]);
//    std::cout << "Hello, World!\n";
    run_tcp_client();
//    run_udp_server();
//    run_tcp_server();
    return 0;
}
