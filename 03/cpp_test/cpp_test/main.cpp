//
//  main.cpp
//  cpp_test
//
//  Created by delims on 2022/3/1.
//

#include <iostream>
#include <sys/fcntl.h>
#include <vector>
#include <thread>

//extern void _03_07();
extern void _03_09(const char *);


int main(int argc, const char * argv[]) {
    
//    _03_06();
//    _03_07();
    
    printf("%s\n",argv[0]);
    
    _03_09(argv[1]);

    return 0;
}

