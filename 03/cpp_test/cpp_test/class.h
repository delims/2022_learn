//
//  class.cpp
//  cpp_test
//
//  Created by delims on 2022/4/17.
//

#include <stdio.h>
#include <iostream>
#include <sys/fcntl.h>
#include <vector>
#include <thread>
#include <unistd.h>

class Apple
{
public:
    long color;
    long weight;

    Apple(){
        printf("apple constructor\n");
    }
    ~Apple(){
        printf("apple destructor %p\n",this);
    }
    Apple(const Apple& apple) {
        printf("apple copy constructor\n");
    }
//    Apple(const Apple&& apple) {
//        printf("apple move constructor\n");
//    }
//    Apple& operator = (const Apple &apple) {
//        printf("apple assign copy constructor\n");
//        return *this;
//    }
//    Apple& operator = (const Apple &&apple) {
//        printf("apple assign move constructor\n");
//        return *this;
//    }
//    Apple* operator& () {
//        return this;
//    }
//    const Apple* operator& () const {
//        return this;
//    }
    
    void operator()(){
        printf("call ()\n");
    }
    void operator()(int,int){
        printf("call (int,int)\n");
    }
};

void prints(const char* p, size_t size);
void print_int_to_string(unsigned int);
void print_long_to_string(unsigned long);
void print_int(int value);
void print_u_int(unsigned int value);
void println();
