//
//  http_server.hpp
//  NavigationRouter
//
//  Created by delims on 2022/3/28.
//

#ifndef http_server_hpp
#define http_server_hpp

#include <stdio.h>
#include <sys/types.h>
#include <map>
#include <iostream>
#include <functional>
#include <vector>

#include "../model/HttpRequest.h"
#include "../model/HttpResponse.h"

using namespace std;


typedef std::function<void(HttpRequest* request, HttpResponse *response)> request_block;

//typedef std::function<void(int)> complete_block;

class HttpServer {
private:
    bool initialized = false;
    bool is_startup = false;
    unsigned short port;
    map<string,request_block> get_block_map;
    map<string,request_block> post_block_map;
    
    int startup(ushort port);

    void init();
    void error_exit(const char *desc);
    void accept_request(int sock);
    void response_client(int sock,HttpResponse &res);
    void run_loop();
    int read_line(int sock, char *buf, int size);
    int listen(ushort port);
    int accept(int sock);
public:
    HttpServer() = delete;
    HttpServer(ushort port);
    HttpServer(const HttpServer& a) = delete;
    HttpServer& operator=(const HttpServer& a) = delete;
    
    void get(string url,request_block);
    void post(string url,request_block);
};



#endif /* http_server_hpp */
