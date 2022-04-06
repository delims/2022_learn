//
//  _04_06.cpp
//  cpp_test
//
//  Created by delims on 2022/4/6.
//

#include "_04_06.hpp"
#include <unistd.h>
#include <fcntl.h>

struct Apple {
    int a;
    int b;
    Apple(){
        
    }
    ~Apple() {
        
    }
    long operator()(long x) {
        return a + x;
    }
};

static void func() {

}

void _04_06() {
//    for (int i = 0; i < 10; i++) {
//        printf("%d\n",i);
//    }
//    int a = 10;
//    int b = 20;
//    {
//        int c = 0x20;
//    }
//    {
//        Apple a;
//    }
//    long c;
//    long a = 4;
//    int b = a >= 3L ? 2 : 0xff;
//    // float 类型的相关指令
//    float a = 12.1234;
//    float b = a;
//    float c = b + 12.3;
//    func();
    
//    int a = 10;
//
//    auto f = []() {
//        printf("hello \n");
//    };
//    f();
    
//    Apple a;
//    a.a = 100;
//    long b = a(200);
    
    int a = 100;
    
//    printf("%ld\n",b);
    int fd = open("/dev/disk0", O_RDONLY);
    
    printf("%d\n",fd);
    
}

// if (%rdx >= 0x3) {%eax = %ecx}
//0x1000082ae <+30>: cmpq   $0x3, %rdx
//0x1000082b2 <+34>: cmovgel %ecx, %eax


// if (%rdx > 0x3) {%eax = %ecx}
//0x1000082ae <+30>: cmpq   $0x3, %rdx
//0x1000082b2 <+34>: cmovgl %ecx, %eax
