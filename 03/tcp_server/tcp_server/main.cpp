//
//  main.cpp
//  tcp_server
//
//  Created by delims on 2022/3/7.
//

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h> // IPPROTO_TCP 等协议定义
#include <arpa/inet.h>  // 字节序转换相关函数
#include <netinet/tcp.h> // get tcp status
#include <unistd.h>
//struct sockaddr_in {
//    __uint8_t       sin_len;
//    sa_family_t     sin_family;
//    in_port_t       sin_port;
//    struct  in_addr sin_addr;
//    char            sin_zero[8];
//};

extern int run_tcp_server();

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    //
//    run_tcp_server();
//    return 0;
    
    
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
    
    
//    printf("%x \n",htonl(inet_addr("128.128.128.129")));
    
//    int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//
//    sockaddr_in addr_in;
////    sockaddr_in6 addr_in6;
//
//    addr_in.sin_family = AF_INET;
//    addr_in.sin_port = htons(16536);
////    addr_in.sin_addr.s_addr = htonl(INADDR_ANY);
//    addr_in.sin_addr.s_addr = inet_addr("127.0.0.1");
//
//    int tr = 1;
//    int result = 0;
//    printf("socket created: %d \n",server_socket);
//
//    result = setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &tr, sizeof(tr));
//    if (result == 0) {
//        printf("setsockopt success\n");
//    } else return 0;
//
//    result = bind(server_socket, (struct sockaddr*)&addr_in, sizeof(addr_in));
//    if (result == 0) {
//        printf("bind success\n");
//    } else return 0;
//
//    result = listen(server_socket, 20);
//    if (result == 0) {
//        printf("listen success\n");
//    } else return 0;
//
//    sockaddr_in client_sockaddr_in;
//    socklen_t client_sock_len = sizeof(client_sockaddr_in);
//    while (1) {
//        printf("begin accept ...\n");
//        int client_socket = accept(server_socket, (struct sockaddr*)&client_sockaddr_in, &client_sock_len);
//        printf("client coming ...\n");
//
//        while (1) {
//            char buffer[1024] = {0};
//            ssize_t size = read(client_socket, buffer, 1024);
////            printf("receive bytes lenth = %ld \n",size);
//            printf("%s ",buffer);
//            memset(buffer, '\0', 1024);
//            if (size == -1) {
//                printf("error: %s \n",strerror(errno));
//                printf("connet lost  %d  %d\n",close(client_socket),close(server_socket));
//                return 0;
//            }
//
////            sleep(10);
//            usleep(100);
//        }
//    }
//

//    printf("%d\n",server_socket);
//    printf("addr_in size = %d\n",sizeof(addr_in6));

    return 0;
}
