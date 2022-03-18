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
#include <cstdlib>

#pragma pack(1)

struct tcp_message {
    unsigned short header = 0xEEFF;
    unsigned short length;
    char body[0];
};

struct tcp_heart_t {
    char type = 2;
    unsigned long latitude:40;
    unsigned long longitude:40;
    short speed;
    char status;
};

struct info_t {
    char type = 1;
    char id[16];
    info_t(){
        type = 1;
        memcpy(id, "NJ4GKBOAV0000029", sizeof(id));
    }
};

char crc(const char* bytes, size_t size) {
    char res = 0;
    int j = -1;
    while (++j < size) res ^= bytes[j];
    return res;
}

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
//        sprintf(buffer, "% 6d\n",number++);
        tcp_message msg;
        
        info_t info;
        msg.length = sizeof(info);
        int totalsize = sizeof(msg) + sizeof(info) + 1;
        char *bytes = (char*) malloc(totalsize);
        memcpy(bytes, &msg, sizeof(msg));
        memcpy(bytes + sizeof(msg), &info, sizeof(info));
        bytes[totalsize-1] = crc(bytes, totalsize-1);
        write(sock, bytes, totalsize);
        free(bytes);
        
#define coor_scale 100000000
#define coor_scale_1 0.00000001
        int count = 0;
        while (1) {
            tcp_heart_t info;
            info.type = 2;
            info.status = 1;
            info.longitude = 160.12343 * coor_scale - (0.000001 * count++);
            info.latitude = 40.12343 * coor_scale;
            info.speed = 100;
            
            msg.length = sizeof(info);
            int totalsize = sizeof(msg) + sizeof(info) + 1;
            char *bytes = (char*) malloc(totalsize);
            memcpy(bytes, &msg, sizeof(msg));
            memcpy(bytes + sizeof(msg), &info, sizeof(info));
            bytes[totalsize-1] = crc(bytes, totalsize-1);
            write(sock, bytes, totalsize);
            free(bytes);
            sleep(6);

        }
        
        
        printf("%s ",buffer);
        sleep(6);
        
    }
}
