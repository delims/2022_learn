//
//  main.cpp
//  http_server
//
//  Created by delims on 2022/3/29.
//

#include <iostream>
#include <unistd.h>
#include <signal.h>

#include "http_server/http_server.hpp"

void sig_handler(int sig) {
   
    cout << "signal : " << sig << endl;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    //    std::cout << "Hello, World!\n";
    
    signal(SIGPIPE, sig_handler);
    
    HttpServer server(3600);
    
    server.post("/startTask", [](HttpRequest *req, HttpResponse *resp){
        cout << req->method << endl;
        cout << req->url << endl;
        cout << req->body.data() << endl;
        printf("invoke \n");
        const char* body = "{\"code\":1200}";
        resp->body.insert(resp->body.end(), body, body + strlen(body));
    });
    
    sleep(250000);
    return 0;
}
