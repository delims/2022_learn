//
//  class.cpp
//  cpp_test
//
//  Created by delims on 2022/4/19.
//

#include <stdio.h>
#include "class.h"
void prints(const char* p, size_t size) {
    for (int i = 0;i < size ; i ++) printf("%c",*(p+i));
    printf("\n");
}

void print_int_to_string(unsigned int value){
    prints((const char*)&value, sizeof(value));
}
void print_long_to_string(unsigned long value){
    prints((const char*)&value, sizeof(value));
}
void print_int(int value) {
    printf("%d\n",value);
}
void print_u_int(unsigned int value){
    printf("%u\n",value);
}
void println() {printf("\n");}
