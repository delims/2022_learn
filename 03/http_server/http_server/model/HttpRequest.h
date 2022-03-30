//
//  HttpRequest.h
//  NavigationRouter
//
//  Created by delims on 2022/3/29.
//

#ifndef HttpRequest_h
#define HttpRequest_h

#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct HttpRequest {
    string method;
    string url;
    map<string,string> headers;
    vector<char> body;
    HttpRequest(){
        method = "";
        url = "";
        headers.clear();
        body.clear();
    }
};

#endif /* HttpRequest_h */
