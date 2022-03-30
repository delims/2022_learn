//
//  http_server.cpp
//  NavigationRouter
//
//  Created by delims on 2022/3/28.
//

#include "http_server.hpp"

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <thread>

#define SERVER_STRING "Server: Awesome HttpServer by zhuchongyao\r\n"

HttpServer::HttpServer(ushort port){
    startup(port);
}

void HttpServer::error_exit(const char *desc)
{
    perror(desc);
//    exit(0);
}

int HttpServer::listen(ushort port)
{
    int sock = 0;
    int on = 1;
    struct sockaddr_in name;
    sock = ::socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) error_exit("socket");
    memset(&name, 0, sizeof(name));
    name.sin_family = AF_INET;
    name.sin_port = htons(port);
    name.sin_addr.s_addr = htonl(INADDR_ANY);
//    name.sin_addr.s_addr = ::inet_addr("127.0.0.1");
    if (::setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0) error_exit("setsockopt failed");
    if (::bind(sock, (struct sockaddr *)&name, sizeof(name)) < 0) error_exit("bind");
    if (::listen(sock, 15) < 0) error_exit("listen");
    return sock;
}

int HttpServer::startup(ushort port)
{
    if (is_startup) return -1;
    is_startup = true;
    
    auto runloop = [this,port](){
        int sock = this->listen(port);
        printf("http server running on port %d ..\n", port);
        this->accept(sock);
        printf("thread exit \n");
    };
    std::thread(runloop).detach();
    return 0;
}

void HttpServer::init()
{
    if (initialized == false) return;
    initialized = true;
}

void HttpServer::get(string url, request_block block) {
    get_block_map[url] = block;
}

void HttpServer::post(string url, request_block block) {
    post_block_map[url] = block;
}

int HttpServer::read_line(int sock, char *buf, int size) {
    int i = 0;
    char c = '\0';
    ssize_t n;
    
    while ((i < size - 1) && (c != '\n'))
    {
        n = recv(sock, &c, 1, 0);
//        printf("read = %ld\n",n);
        if (n > 0)
        {
            if (c == '\r')
            {
                n = recv(sock, &c, 1, MSG_PEEK);
                if ((n > 0) && (c == '\n')) recv(sock, &c, 1, 0);
                else c = '\n';
            }
            buf[i++] = c;
        } else c = '\n';
        if (n==0) return -1;;
    }
    buf[i] = '\0';
    //    printf("read == %s",buf);
    return i;
}

void HttpServer::response_client(int sock,HttpResponse &res) {
    char buf[1024] = {0};
    strcpy(buf, "HTTP/1.1 200 OK\r\n");
    send(sock, buf, strlen(buf), 0);
    strcpy(buf, SERVER_STRING);
    send(sock, buf, strlen(buf), 0);
    char s[64] = {0};
    time_t t = time(0);
    strftime(s, sizeof(s), "%a, %d %b %Y %H:%M:%S %Z", localtime(&t));
    sprintf(buf, "Date: %s\r\n",s);
    send(sock, buf, strlen(buf), 0);
    sprintf(buf, "Content-Type: application/json;charset=utf-8\r\n");
    send(sock, buf, strlen(buf), 0);
    sprintf(buf, "Connection: Close\r\n");
    send(sock, buf, strlen(buf), 0);
    sprintf(buf, "Transfer-Encoding: chunked\r\n\r\n");
    send(sock, buf, strlen(buf), 0);
    
    size_t clen = res.body.size();
    sprintf(buf, "%zx\r\n",clen);send(sock, buf, strlen(buf), 0);
    send(sock, res.body.data(), clen, 0);
    sprintf(buf, "\r\n0\r\n\r\n");send(sock, buf, strlen(buf), 0);
}

void HttpServer::accept_request(int sock) {

    HttpRequest request;
    char buffer[1024] = {'\0'};
    int size;
    size = read_line(sock, buffer, sizeof(buffer));
    if (size == -1) {
        close(sock);
        return;
    }
    int i = 0;
    while (buffer[i] != ' ' && buffer[i] != '\0') request.method += buffer[i++];
    while (buffer[i] == ' ') i++;
    while (buffer[i] != ' ' && buffer[i] != '\0') request.url += buffer[i++];
    
    const char *clen_key = "Content-Length";
    do {
        size = read_line(sock, buffer, sizeof(buffer));
        if (size == -1) {
            close(sock);
            return;
        }
        string key,value;
        char *colon = strchr(buffer, ':');
        if (colon) {
            colon[0] = '\0';
            key = buffer;
            value = colon + 2;
            value.pop_back();
            request.headers[key] = value;
        }
        printf("key = %s \n",key.c_str());

    } while (size > 2);
    
    size_t clen = 0;
    if (request.headers[clen_key].size()) {
        clen = strtod(request.headers[clen_key].c_str(), NULL);
    }
//    cout << request.method << endl;
//    cout << request.url << endl;
//    cout << clen << endl;
    
    char ch;
    while (clen--) {
        recv(sock, &ch, 1, 0);
        request.body.push_back(ch);
    }
    
    
    map<string,request_block> *blocks = request.method == "POST" ? &post_block_map :
    request.method == "GET" ? &get_block_map : nullptr;
    
    if (blocks == nullptr) {
        HttpResponse response;
        const char *body = "{\"code\":-1,\"message\":\"This method is not supported\"}";
        response.body.insert(response.body.end(), body, body + strlen(body));
        response_client(sock, response);
        close(sock);
        return;
    }
    
    map<string,request_block>::iterator iter = blocks->begin();
    while (iter != blocks->end()) {
        if (iter->first == request.url) {
            HttpResponse response;
            iter->second(&request,&response);
            response_client(sock, response);
            close(sock);
            return;
        }
        iter++;
    }
    
    HttpResponse response;
    const char *body = "{\"code\":-1,\"message\":\"api not implemented\"}";
    response.body.insert(response.body.end(), body, body + strlen(body));
    response_client(sock, response);
    close(sock);
}

int HttpServer::accept(int sock)
{
    int client_sock = 0;
    struct sockaddr_in client_name;
    socklen_t  client_name_len = sizeof(client_name);
    while (1)
    {
        client_sock = ::accept(sock,(struct sockaddr *)&client_name,&client_name_len);
        if (client_sock == -1) {
            printf("client sock error \n");continue;
        } else {
            printf("http request coming... ip: %s port: %d \n",inet_ntoa(client_name.sin_addr),client_name.sin_port);
        }
        thread(&HttpServer::accept_request,this,client_sock).detach();
    }
    return 0;
}
