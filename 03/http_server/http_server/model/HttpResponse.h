//
//  HttpResponse.h
//  NavigationRouter
//
//  Created by delims on 2022/3/29.
//

#ifndef HttpResponse_h
#define HttpResponse_h

#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct HttpResponse {
    int status;
    map<string,string> headers;
    vector<char> body;
};

#endif /* HttpResponse_h */
