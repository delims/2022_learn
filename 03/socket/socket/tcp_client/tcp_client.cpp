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
#include <thread>
#include <vector>
#include <mutex>

void *tcp_client_read(void* arg);

#pragma pack(1)

struct tcp_message {
    unsigned short header = 0xEEFF;
    unsigned short length;
    char body[0];
};

struct from_tcp_heart_t {
    char type = 2;
    unsigned long latitude:40;
    unsigned long longitude:40;
    short speed;
    char status;
    char task_id[32];
};

struct from_tcp_device_info_t {
    char type = 1;
    char device_no[16];
};

struct info_t {
    char type = 1;
    char id[16];
    info_t(){
        type = 1;
        memcpy(id, "NA20220321000001", sizeof(id));
    }
};

struct tcp_task_start_t {
    char type = 3;
    char task_id[32];
};

struct tcp_coor {
    unsigned long latitude:40;
    unsigned long longitude:40;
};


struct to_tcp_task_t {
    char type = 5;
    char task_id[32];
    tcp_coor positions[4];
    unsigned char taskType;
    unsigned char toolType;
    short width;
};

char crc(const char* bytes, size_t size) {
    char res = 0;
    int j = -1;
    while (++j < size) res ^= bytes[j];
    return res;
}

std::vector<char> send_buffer;
std::mutex lock;

int run_tcp_client () {
    
    sockaddr_in server_addr_in;
    server_addr_in.sin_family = AF_INET;
//    server_addr_in.sin_addr.s_addr = inet_addr("127.0.0.1");
//    server_addr_in.sin_addr.s_addr = inet_addr("192.168.14.12");
    //    server_addr_in.sin_addr.s_addr = inet_addr("123.124.91.28");
        server_addr_in.sin_addr.s_addr = inet_addr("223.223.187.43");
    server_addr_in.sin_port = htons(50001);
    
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
    
    std::thread(tcp_client_read,(void*)(uintptr_t)sock).detach();
    
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
        
        sleep(1);
//        close(sock);
//        return 0;
//
#define coor_scale   100000000
#define coor_scale_1 0.00000001
        int count = 0;
        int task_start_success = 0;
        while (1) {
            from_tcp_heart_t heart;
            heart.type = 2;
            heart.status = 0;
            heart.longitude = 160.12343 * coor_scale - (0.000001 * count++);
            heart.latitude = 40.12343 * coor_scale;
            heart.speed = 100;
            static int times = 0;
            if (times ++ >= 3) {
                memcpy(heart.task_id, "1c4479c7461a4177a851858485bd6680", 32);
                if (times == 5) heart.status = 1;
                if (times > 6) {
                    heart.status = 0;
                }

            } else
            memcpy(heart.task_id, "00000000000000000000000000000000", 32);
            
            msg.length = sizeof(heart);
            int totalsize = sizeof(msg) + sizeof(heart) + 1;
            char *bytes = (char*) malloc(totalsize);
            memcpy(bytes, &msg, sizeof(msg));
            memcpy(bytes + sizeof(msg), &heart, sizeof(heart));
            bytes[totalsize-1] = crc((const char *)&heart, sizeof(heart));
            ssize_t write_ret = write(sock, bytes, totalsize);
            printf("write %ld bytes \n",write_ret);
//            if (write_ret == -1 )
            free(bytes);
            sleep(6);
            
            
            
//            if(count > 4) {
//                if (task_start_success) {
//                    task_start_success = 0;
//                    std::vector<char> end_buffer;
//                    tcp_message msg;
//                    tcp_task_start_t info;
//                    info.type = 4;
//                    msg.length = sizeof(info);
//                    int totalsize = sizeof(msg) + sizeof(info) + 1;
//                    end_buffer.insert(end_buffer.end(), (const char * )&msg, (const char *)&msg+sizeof(msg));
//                    end_buffer.insert(end_buffer.end(), (const char * )&info, (const char *)&info+sizeof(info));
//                    end_buffer.push_back(crc((const char*)&info, sizeof(info)));
//                    send(sock, &end_buffer[0], end_buffer.size(), 0);
//                    printf("client sent %ld bytes\n",end_buffer.size());
//                }
//            }
            
            if (send_buffer.size() == 0) continue;
            lock.lock();
            //发送开始成功
//            send(sock, &send_buffer[0], send_buffer.size(), 0);
//            task_start_success = 1;
//            printf("client sent %ld bytes\n",send_buffer.size());
//            send_buffer.clear();
            lock.unlock();
        }
        
        printf("%s ",buffer);
        
        sleep(6);
        
    }
}

void *tcp_client_read(void* arg) {
    int sock = (int)(uintptr_t)arg;
    
    std::vector<char> receive_buffer;
    
    while (1) {
        
        char buffer[1024] = {0};
        ssize_t size = recv(sock, buffer, sizeof(buffer), 0);
        if (size <= 0) {
            printf("server closed, client close ret =%d \n",close(sock));
            break;;
        }
        printf("client receive %ld bytes\n",size);
        int len = size;
        for (int i = 0;i < len ;i ++) printf("%02x",buffer[i] & 0xFF);
        printf("\n");
        
        if (size == 82) {
            
//            receive_buffer.insert(receive_buffer.end(), buffer,buffer+size);
            tcp_message msg;
            to_tcp_task_t info;
            msg.length = sizeof(info);
            int totalsize = sizeof(msg) + sizeof(info) + 1;
            
            memcpy(&info, buffer + 4, sizeof(info));
            
            for (int i = 0;i < 4;i++) {
                printf("lat = %f lng = %f \n",info.positions[i].latitude * 0.00000001,info.positions[i].longitude * 0.00000001);
            }
            
            
            //        char *bytes = (char*) malloc(totalsize);
            
//            send_buffer.insert(send_buffer.end(), (const char * )&msg, (const char *)&msg+sizeof(msg));
//            send_buffer.insert(send_buffer.end(), (const char * )&info, (const char *)&info+sizeof(info));
//            send_buffer.push_back(crc((const char*)&info, sizeof(info)));
        }
        
        
//        lock.lock();
        


        
        //        memcpy(bytes, &msg, sizeof(msg));
        //        memcpy(bytes + sizeof(msg), &info, sizeof(info));
        
//        lock.unlock();
        
    }
    
    
    return nullptr;
}
